#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,s[510],a[510];
ll b[510],vis[510],ans;
char ch;
int check(){
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[b[i]]<=now||s[i]==0){
			now++;
		}
	}
	return n-now>=m;
}
void dfs(int now){
	if(now==n+1){
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		b[now]=i;
		vis[i]=1;
		dfs(now+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans;
	return 0;
}
