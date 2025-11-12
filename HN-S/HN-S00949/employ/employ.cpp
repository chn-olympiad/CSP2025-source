#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=505;
int n,m;
int a[505];
bool vis[505];
string s;
int c[505];
ll ans;
void dfs(int p){
	if(p==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]||s[i-1]=='0')++cnt;
		}
		if(n-cnt>=m)++ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[p]=i;
		dfs(p+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=m;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;i++)a[i]=i;
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
