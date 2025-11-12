#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[505],ans;
bool vis[505];
const int mod=998244353;
string s;
void dfs(int i,int cnt){
	if(cnt+n-i<m)return;
	if(i==n){
		if(cnt>=m)ans++;
		ans%=mod;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			vis[j]=1;
			if(s[i]-'0'){
				if(a[j]>i-cnt)dfs(i+1,cnt+1);
				else dfs(i+1,cnt);
			}
			else dfs(i+1,cnt);
			vis[j]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
