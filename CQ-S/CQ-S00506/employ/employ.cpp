#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000005

namespace akakakak{

	int n, m;
	string s;
	int inc[MAXN];
	int ans;

	int suc[MAXN], pre[MAXN];

	inline void Rm(int u){
		suc[pre[u]]=suc[u];
		pre[suc[u]]=pre[u];
		return;
	}

	inline void Rc(int u){
		suc[pre[u]]=u;
		pre[suc[u]]=u;
		return;
	}

	inline void Dfs(int u, int pre){
		if (pre>m) return;
		if (u==n) return ++ans, void();
		if (!s[u+1]){
			if (pre+1>m) return;
			for (int i=suc[0];i<=n;i=suc[i]){
				Rm (i);
				Dfs (u+1, pre+1);
				Rc (i);
			}
		}
		else{
			for (int i=suc[0];i<=n;i=suc[i]){
				Rm (i);
				Dfs (u+1, pre+(inc[i]<=pre));
				Rc (i);
			}
		}
		return;
	}

	int main(){
		cin>>n>>m>>s;
		s=" "+s;
		m=n-m;
		suc[0]=1;
		for (int i=1;i<=n;++i){
			cin>>inc[i];
			pre[i]=i-1;
			suc[i]=i+1;
		}
		pre[n+1]=n;
		Dfs (0, 0);
		cout<<ans<<'\n';
		return 0;
	}
}

int main(){
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	return akakakak::main();
}
