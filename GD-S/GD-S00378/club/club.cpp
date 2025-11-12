#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
#define sco 100010
using namespace std;
ll n,T,a[sco][10],f[10][sco],g[sco][10];
ll t1,t2,t3,ans;
bool cmp(ll x,ll y){
	return g[x][3]-g[x][2]>g[y][3]-g[y][2];
}
void solve(){
	t1=t2=t3=ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",a[i]+1,a[i]+2,a[i]+3);
		g[i][1]=a[i][1];
		g[i][2]=a[i][2];
		g[i][3]=a[i][3];
		sort(g[i]+1,g[i]+4);
		if(a[i][1]>a[i][2] && a[i][1]>a[i][3])f[1][++t1]=i;
		else if(a[i][2]>a[i][1] && a[i][2]>a[i][3])f[2][++t2]=i;
		else f[3][++t3]=i;
		ans+=max(a[i][1],max(a[i][2],a[i][3]));
	}
	sort(f[1]+1,f[1]+t1+1,cmp);
	sort(f[2]+1,f[2]+t2+1,cmp);
	sort(f[3]+1,f[3]+t3+1,cmp);
	if(t1>n/2){
		for(int i=n/2+1;i<=t1;++i){
			ans+=g[f[1][i]][2]-g[f[1][i]][3];
		}
	}
	else if(t2>n/2){
		for(int i=n/2+1;i<=t2;++i){
			ans+=g[f[2][i]][2]-g[f[2][i]][3];
		}
	}
	else if(t3>n/2){
		for(int i=n/2+1;i<=t3;++i){
			ans+=g[f[3][i]][2]-g[f[3][i]][3];
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
