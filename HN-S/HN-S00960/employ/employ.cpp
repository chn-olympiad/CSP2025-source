#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int val[100010],p[100010],vis[100010];
bool check(){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||val[p[i]]<=sum2)sum2++;
		else sum1++;
	}
	if(sum1>=m)return true;
	else return false;
}
void dfs(int now){
	if(now==n+1){
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		p[now]=i;
		vis[i]=1;
		dfs(now+1);
		vis[i]=0;
		p[now]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>val[i];
	dfs(1);
	cout<<ans;
	return 0;
}

