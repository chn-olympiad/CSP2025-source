#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
struct node{
	long long pt1,pt2,pt3,maxi,cha;
};
node a[100005];
long long sum[5];
bool cmp(node x,node y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n;
		long long ans=0;
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].pt1>>a[j].pt2>>a[j].pt3;
			if(a[j].pt1>=a[j].pt2&&a[j].pt1>=a[j].pt3){
				a[j].maxi=1;
				ans+=a[j].pt1;
			}
				
			else if(a[j].pt2>=a[j].pt1&&a[j].pt2>=a[j].pt3){
				a[j].maxi=2;
				ans+=a[j].pt2;
			}
				
			else if(a[j].pt3>=a[j].pt1&&a[j].pt3>=a[j].pt2){
				a[j].maxi=3;
				ans+=a[j].pt3;
			}
				
			if(a[j].pt1<=max(a[j].pt2,a[j].pt3)&&a[j].pt1>=min(a[j].pt2,a[j].pt3))
				a[j].cha=max(a[j].pt2,a[j].pt3)-a[j].pt1;
			if(a[j].pt2<=max(a[j].pt1,a[j].pt3)&&a[j].pt2>=min(a[j].pt1,a[j].pt3))
				a[j].cha=max(a[j].pt1,a[j].pt3)-a[j].pt2;
			if(a[j].pt3<=max(a[j].pt1,a[j].pt2)&&a[j].pt3>=min(a[j].pt1,a[j].pt2))
				a[j].cha=max(a[j].pt1,a[j].pt2)-a[j].pt3;
			sum[a[j].maxi]++;
		}
		sort(a+1,a+n+1,cmp);
		long long w=max(sum[1],max(sum[2],sum[3]))-(n/2),maxl;
		if(sum[1]>=sum[2]&&sum[1]>=sum[3]) maxl=1;
		else if(sum[2]>sum[1]&&sum[2]>sum[3]) maxl=2;
		else if(sum[3]>=sum[1]&&sum[3]>=sum[2]) maxl=3;
		for(int j=1;j<=n,w>0;j++){
			if(a[j].maxi==maxl){
				ans-=a[j].cha;
				w--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
