#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
char h[505];
int n,m,ans=0;
int used[505];
int s[505],c[505];
void dfs(int x,int sum,int fail){
	if(s[n]-s[x-1]+sum<m) return;
	if(x>n){
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==1) continue;
		used[i]=1;
		if(fail>=c[i]||s[x]-s[x-1]==0) dfs(x+1,sum,fail+1);
		else dfs(x+1,sum+1,fail);
		used[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",h+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+h[i]-'0';
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0,0);
	cout<<ans<<endl;
}
