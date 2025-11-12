#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n,T,dp[N];
struct hh{
	int a,b,c;
}p[N];
ll ans;
void dfs(ll sua,ll sub,ll suc,ll ca,ll cb,ll cc,ll t){
	if( ca > n/2 || cb > n/2 || cc > n/2) return;
	if( t == n+1 ){
		ans = max( ans, sua + sub + suc);
		return;
	}
	dfs( sua + p[t].a, sub , suc , ca + 1 , cb ,cc , t+1);
	dfs( sua , sub + p[t].b, suc , ca  , cb + 1,cc , t+1);
	dfs( sua , sub , suc + p[t].c, ca , cb ,cc + 1 , t+1);
	return;
}
bool cmp1( hh i,hh j){
	return i.a > j.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while ( T-- ){
		cin >> n;
		ans = 0;
		bool ok = true,flag = true;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			if( p[i].b != 0 || p[i].c != 0) ok = false;
		}
		if( ok ){
			sort( p+1,p+n+1,cmp1 );
			for(int i = 1;i <= n/2;i++) ans += p[i].a;
		}else dfs( 0 , 0 , 0 , 0 , 0 , 0 , 1);
		printf("%lld\n",ans);
	}
	return 0;
}

