#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,ans,m,arr[100],nxt[100],pre[100],jl[100],vis[100];
string s;
void dfs (int x) {
	if(x>n) {
		int a=0,b=0;//cout<<"\n";
		for(int i=1;i<=n;i++) {//cout<<jl[i]<<" ";
			if(arr[jl[i]]<=a) continue;
			if(s[i-1]=='0') {
				a++;
			}else {
				b++;
			}
		}
		if(b>=m) {
			ans++;
			ans%=Mod;
		}
		return;
	}
	for(int i=0;i<=n;i=nxt[i]) {
		if(i==0) continue;
		int a=pre[i],b=nxt[i];
		nxt[a]=b;
		pre[b]=a;
//		if(vis[i]==0) {vis[i]=1;
			jl[x]=i; 
			dfs(x+1);
			jl[x]=0;//vis[i]=0;
//		}
		
		pre[b]=i;
		nxt[a]=i;
	}
}
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	if(n>10) {
		cout<<0<<" ";
		return 0;
	}
	nxt[0]=1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		nxt[i]=i+1;
		pre[i]=i-1;
	}
	dfs(1);
	cout<<ans<<" ";
	return 0;
}

