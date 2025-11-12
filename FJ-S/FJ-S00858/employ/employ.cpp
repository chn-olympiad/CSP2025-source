#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
const long long mod=998244353;
char s[N];
long long fac[N],ans;
int n,m;
bool vis[N];
int c[N],a[N];
void dfs(int x){
	if(x==n+1){
		int tot=0,bad=0;
		for(int i=1;i<=n;i++){
			if(bad>=a[i])bad++;
			else {
				if(s[i]=='0')bad++;
				else tot++;
			}
		}
		if(tot>=m){
			ans++;
			if(ans>=mod)ans-=mod; 
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=c[i];
			dfs(x+1);
			vis[i]=0;
			a[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(1);
	cout<<ans;
	return 0;
}
