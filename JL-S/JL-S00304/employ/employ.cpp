#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define int long long
int c[505];
int n,m;
int a[505];
int ans=0;
string s;
int vis[505];
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		int num=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
			else if(s[i-1]=='1'){
				num++;
			}
			else cnt++;
		}
		if(num>=m){
			ans++;
			ans%=mod;
		}
		else return;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
		cin>>s;bool b=true;
	for(int i=0;i<n;i++){
		if(s[i]=='0')b=false;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else if(b){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}