#include<bits/stdc++.h>
using namespace std;
const int N=505;
bool vis[N];char s[N];int n,m,ans,a[N],c[N];
void dfs(int u){
	if(u==n+1){
		int t=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&cnt<c[a[i]])++t;
			else ++cnt;
		}ans+=(t>=m);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])a[u]=i,vis[i]=1,dfs(u+1),vis[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	
	return 0;
}
