//余诗琪 GZ-S00031 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m,a[505];
ll ans;
bool vis[505];
char s[505];
void dfs(int day,int cnt,int pass) {
	if(day==n+1&&cnt>=m) {
		ans++;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]&&pass<a[i]) {
			if(s[day]=='0') {
				vis[i]=1;
				dfs(day+1,cnt,pass+1);
				vis[i]=0;
			} else {
				vis[i]=1;
				dfs(day+1,cnt+1,pass);
				vis[i]=0;
			}
		}else if(!vis[i]&&pass>=a[i]) {
			vis[i]=1;
			dfs(day+1,cnt,pass+1);
			vis[i]=0;
		}
	}
	return;
}
bool flag=1;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s[i];
		if(s[i]=='0') flag=0;
	}
	for(int i=1; i<=n; i++) cin>>a[i];
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*n%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
