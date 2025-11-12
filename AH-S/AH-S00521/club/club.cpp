#include<bits/stdc++.h>
using namespace std;
struct node{
	int d[5];
}a[100005];
int T,n;
bool cmp(node x,node y){
	return x.d[0]<y.d[0];
}
bool cmp1(node x,node y){
	return x.d[4]<y.d[4];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int c1=0,c2=0,c3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(a[i].d[1]>=a[i].d[2]&&a[i].d[1]>=a[i].d[3]){
				a[i].d[0]=1;
				c1++;
				ans+=a[i].d[1];
			}else if(a[i].d[2]>=a[i].d[1]&&a[i].d[2]>=a[i].d[3]){
				a[i].d[0]=2;
				c2++;
				ans+=a[i].d[2];
			}else if(a[i].d[3]>=a[i].d[1]&&a[i].d[3]>=a[i].d[2]){
				a[i].d[0]=3;
				c3++;
				ans+=a[i].d[3];
			}
		}
		sort(a+1,a+n+1,cmp);
		if(c1>n/2){
			for(int i=1;i<=c1;i++){
				a[i].d[4]=min(a[i].d[1]-a[i].d[2],a[i].d[1]-a[i].d[3]);
			}
			sort(a+1,a+c1+1,cmp1);
			for(int i=1;i<=c1-n/2;i++){
				ans-=a[i].d[4];
			}
		}
		if(c2>n/2){
			for(int i=c1+1;i<=c1+c2;i++){
				a[i].d[4]=min(a[i].d[2]-a[i].d[1],a[i].d[2]-a[i].d[3]);
			}
			sort(a+c1+1,a+c1+c2+1,cmp1);
			for(int i=c1+1;i<=c1+c2-n/2;i++){
				ans-=a[i].d[4];
			}
		}
		if(c3>n/2){
			for(int i=c1+c2+1;i<=n;i++){
				a[i].d[4]=min(a[i].d[3]-a[i].d[1],a[i].d[3]-a[i].d[2]);
			}
			sort(a+c1+c2+1,a+n+1,cmp1);
			for(int i=c1+c2+1;i<=n/2;i++){
				ans-=a[i].d[4];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
