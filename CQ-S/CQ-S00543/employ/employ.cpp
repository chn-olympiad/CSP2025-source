#include<bits/stdc++.h>
using namespace std;
int n,m,vis[100005];
char s[100005];
int a[100005];
long long ans;
void dfs(int x,int r,int sr,int l){
//	printf("%d ",x);
	if(r>=m){
		ans++;
		ans%=998244353;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		if(sr-r>=a[i]||s[l+1]=='0')dfs(i,r,sr+1,l+1);
		else dfs(i,r+1,sr+1,l+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i];
//	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
} 
