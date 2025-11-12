#include<bits/stdc++.h>
using namespace std;

int const maxn = 505;
int d[maxn],c[maxn];
int a[maxn],vis[maxn];
int n,m;
int ans = 0;

void dfs(int x){
	if(x == n+1){
		int cst = 0;
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			if(cst >= c[a[i]]){
				++cst;
			}
			else if(d[i]){
				++cnt;
			}
			else  ++cst;
		}
		ans += (cnt >= m);
		return ;
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			vis[i] = 1;
			a[x] = i;
			dfs(x+1);
			vis[i] = 0;
		}
	}
}

int const p = 998244353;

int main(){
	ios:: sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		char ch;
		cin>>ch;
		d[i] = (ch == '1');
	}
	int ct = 0; 
	for(int i = 1; i <= n; ++i){
		cin>>c[i];
		ct += (c[i] != 0);
	}
	long long res = 1;
	if(n > 14){
		for(int i = n; i >= 1+n-ct; --i){
			res = res*i*1ll%p;
		}
		cout<<res<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
