#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 505;
const int MOD = 998244353;
int n,m;
string ins;
bool s[N],vis[N];
int c[N];
ll ans = 0ll;
void dfs(int x,int cnt){
	//cout<<x<<" "<<cnt<<endl;
	if(x > n){
		if(cnt >= m)ans = (ans+1)%MOD;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i] = 1;
		//cout<<i<<" "<<x-1-cnt<<" "<<c[i]<<endl;
		if(x-1-cnt >= c[i])dfs(x+1,cnt);
		else{
			if(s[x])dfs(x+1,cnt+1);
			else dfs(x+1,cnt);
		}
		vis[i] = 0;
	}
}
bool f = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>ins;
	for(int i=0;i<n;++i){
		if(ins[i] == '0')s[i+1] = 0;
		else s[i+1] = 1;
		f = (f&&s[i+1]);
	}
	for(int i=1;i<=n;++i)cin>>c[i],f = (f&&c[i]);
	if(f){
		ans = 1ll;
		for(int i=1;i<=n;++i){
			ans = (ans*i)%MOD;
		}
	}else dfs(1,0);
	printf("%lld",ans);
	return 0;
}
