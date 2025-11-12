#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
const int N=15;
int n,m,c[N],a[N],vis[N],res; char s[N];
void dfs(int x){
	if(x==n+1){
		int ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0') ++ans;
			else if(ans>=c[a[i]]) ++ans;
		res+=n-ans>=m;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) a[x]=i,vis[i]=1,dfs(x+1),vis[i]=0;
}
void HitachiMako(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	dfs(1),printf("%d",res);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	while(T--) HitachiMako();
	return 0;
} 
