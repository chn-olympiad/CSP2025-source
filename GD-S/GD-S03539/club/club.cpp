#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll T,n,ans,k[5][100005],kd[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll a[5];
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		ans=0;
		kd[1]=kd[2]=kd[3]=0;
		for(ll i=1;i<=n;i++){
			ll zd=0,cd=0;
			for(ll j=1;j<=3;j++){
				scanf("%lld",&a[j]);
				if(a[j]>zd){
					cd=zd,zd=a[j];
				}
				else if(a[j]>cd){
					cd=a[j];
				}
			}
			ans+=zd;
			for(ll j=1;j<=3;j++){
				if(a[j]==zd){
					k[j][++kd[j]]=cd-zd;
				}
			}
		}
		sort(k[1]+1,k[1]+kd[1]+1),
		sort(k[2]+1,k[2]+kd[2]+1),
		sort(k[3]+1,k[3]+kd[3]+1);
		for(ll i=1;i<=3;i++){
			while((kd[i]<<1)>n){
//				cout<<i<<endl;
				ans+=k[i][kd[i]],kd[i]--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
