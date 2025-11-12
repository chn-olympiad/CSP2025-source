#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int n,m,c[502];
ll mod = 998244353,ans = 0;
string s;
bool flag = 0;
int t[502];
bool f[502];
void dfs(int u){
	if(u==n+1){
		int cnt = 0,tui = 0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||tui>=c[t[i]]){
				tui++;
				continue;
			}
			cnt++;
		}
		if(cnt>=m)ans++;
		ans = ans%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1)continue;
		f[i] = 1;
		t[u] = i;
		dfs(u+1);
		t[u] = 0;
		f[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	fr(i,1,n)cin>>c[i];
	for(int i=0;i<s.size();i++)if(s[i]!='1')flag = 1;
	if(flag==0){
		ll aans = 1;
		for(int i=2;i<=n;i++)aans = aans*i%mod;
		cout<<aans;
	}else{
		dfs(1);
		cout<<ans%mod;
	}
	return 0;
}

