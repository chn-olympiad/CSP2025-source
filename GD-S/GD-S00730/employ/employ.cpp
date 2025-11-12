#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,ans;
int a[20],b[20],c[20],s[20];
int flag=0;
void solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!s[i]||cnt>=c[a[i]]){
			cnt++;
		} 
	}
	if(n-cnt>=m)
		ans++;
	ans%=mod;
}
void dfs(int x){
	if(x>n){
		solve();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			a[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int x;
	cin>>n>>m;
	x=n;
	string st;
	cin>>st;
	for(int i=0;i<n;i++){
		s[i]=st[i]-'0';
		if(s[i]==0)flag=1;
	}
	int t=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)t--;
	}
	if(t<m){
		cout<<0;
		return 0;
	}
	if(!flag){
		ans=1;
		for(int i=1;i<=x;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	else dfs(1);

	return 0;
}

