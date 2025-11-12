#include<bits/stdc++.h>
using namespace std;
int t,n;
struct S{
	int x,y,z;
}a[100005];
bool cmp1(S a,S b){
	return a.x<b.x;
}
bool cmp2(S a,S b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
bool cmp3(S a,S b){
	if(a.y==b.y) return a.x<b.x;
	else return a.y<b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int sum=0;
		bool flag=1,f=1;
		for(int j=1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			if(a[j].y!=0||a[j].z!=0){
				flag=0;
			}
			if(a[j].z!=0) f=0;
		}
		int sum2=0;
		if(flag==1){
			sort(a+1,a+n+1,cmp1);
			for(int j=n;j>n/2;j--){
				sum+=a[j].x;
			}
			cout<<sum<<endl;
		}
		sum=0;
		else if(f==1){
			sort(a+1,a+n+1,cmp2);
			for(int j=1;j<=n;j++){
				if(j<=n/2) sum+=a[j].x;
				if(j>n/2) sum+=a[j].y;
			}
			sort(a+1,a+n+1,cmp3);
			for(int j=1;j<=n;j++){
				if(j<=n/2) sum2+=a[j].y;
				if(j>n/2) sum2+=a[j].x;
			}
			cout<<sum<<" "<<max(sum,sum2)<<" "<<sum2<<endl;
		}
	}
	return 0;
}
