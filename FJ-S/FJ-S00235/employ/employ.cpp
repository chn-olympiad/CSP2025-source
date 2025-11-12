#include <iostream>
#include <cstdio>
#define ll long long
#define N 200005
#define INF (ll)1e18

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
}
ll n, m, c[N], a[N], ans;
char s[N];
const ll mod=998244353;
bool vis[N];
void dfs(ll x){
	if(x==n+1){
		ll sum=0, cnt=0;
		for(int i=1; i<=n; i++){
			if(sum>=c[a[i]]) sum++;
			else if(s[i]=='0') sum++;
			else cnt++;
//			cout<<a[i]<<' '<<s[a[i]]<<endl;
		}
//		cout<<cnt<<endl;
		ans=(ans+(cnt>=m))%mod;
		return;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		vis[i]=1, a[x]=i;
		dfs(x+1);
		vis[i]=0, a[x]=0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n=rd(), m=rd();
	scanf(" %s", s+1);
	for(int i=1; i<=n; i++) c[i]=rd();
	dfs(1);
	printf("%lld\n", ans%mod);

	return 0;
}
/*

*/

