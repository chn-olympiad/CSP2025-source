#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,ans,n2;
struct node{
	ll j1,j2,j3,cha,ma;
};
node a[100005];
ll js[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	for(int i=1;i<=T;i++)
	{
		ans=0;
		for(int j=1;j<=3;j++)
		{
			js[j]=0;
		}
		scanf("%lld",&n);
		n2=n/2;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld%lld%lld",&a[j].j1,&a[j].j2,&a[j].j3);
			if(a[j].j1>=a[j].j2&&a[j].j1>=a[j].j3){
				js[1]++;
				a[j].ma=1;
				ans+=a[j].j1;
				a[j].cha=a[j].j1-max(a[j].j2,a[j].j3);
			}else if(a[j].j2>=a[j].j1&&a[j].j2>=a[j].j3){
				js[2]++;
				a[j].ma=2;
				ans+=a[j].j2;
				a[j].cha=a[j].j2-max(a[j].j1,a[j].j3);
			}else{
				js[3]++;
				a[j].ma=3;
				ans+=a[j].j3;
				a[j].cha=a[j].j3-max(a[j].j1,a[j].j2);
			}
		}
		priority_queue<ll,vector<ll>,greater<ll> > q;
		for(int j=1;j<=3;j++)
		{
			if(js[j]>n2){
				js[j]-=n2;
				for(int k=1;k<=n;k++)
				{
					if(a[k].ma==j){
						q.push(a[k].cha);
					}
				}
				for(int k=1;k<=js[j];k++)
				{
					ans-=q.top();
					q.pop();
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
