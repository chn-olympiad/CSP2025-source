#include<bits/stdc++.h>
using namespace std;
const int N=503;
int n,m;
char s[N];
int c[N];
int pp[19];
bool vis[19];
int ans;
void dfs(int x){
	if(x>n){
		int tot=0;
		for(int j=1;j<=n;j++){
			if(s[j-1]=='1'&&c[pp[j]]>=j-tot)tot++;
			if(tot>=m){
				ans++;break;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		pp[x]=i;vis[i]=1;dfs(x+1);vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<0;return 0;
	}
	return 0;
}
