#include<bits/stdc++.h>
using namespace std;
const int N=114;
int a[N],b[N],n,m,ans,vis[N];
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=b[i]||s[i]=='0')cnt++;
	}
	return n-cnt>=m;
}
void dfs(int x){
	if(x>n){
		ans+=check();
		// for(int i=1;i<=n;i++)cout<<b[i]<<' ';cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		b[x]=a[i];
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
}