/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct iii{
	ll a,b,c;
}a[100005];
ll T,n,mx=-1;
void dfs(ll sa,ll sb,ll sc,ll ans,ll d){
	if(d>n){
		mx=max(mx,ans);
		return;
	}
	if(sa+1<=n/2)dfs(sa+1,sb,sc,ans+a[d].a,d+1);
	if(sb+1<=n/2)dfs(sa,sb+1,sc,ans+a[d].b,d+1);
	if(sc+1<=n/2)dfs(sa,sb,sc+1,ans+a[d].c,d+1);
}
bool cmp(iii x,iii y){
	return x.a+x.b+x.c>y.a+y.b+y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		mx=-1;
		bool fa=1,fb=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b!=0||a[i].c!=0)fa=0;
		}
		if(fa){
			ll ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			printf("%lld",ans);
		}else{
			dfs(0,0,0,0,1);
			printf("%lld\n",mx);
		}
		
	}
	return 0;
} 
