#include<bits/stdc++.h>
using namespace std;
int n,m;
char x[15];
int a[15],b[15],ans;
bool vis[15];
inline void check(){
	int now=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(x[i]=='0') now++;
		else {
			if(cnt>=b[i]) now++;
			else cnt++;
		}
	}
	if(cnt>=m) ans++;
	return ;
}
inline void dfs(int x){
	if(x==n+1) check();
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		b[x]=a[i];
		dfs(x+1);
		b[x]=0;
		vis[i]=false;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
