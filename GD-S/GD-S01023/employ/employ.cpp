#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define mod 998244353
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,c[505],ans,f[505],a[505];
string s;
void dfs(int k,int cnt){
	if(k==n+1){
		if(cnt<=n-m) ans=(ans+1)%mod;
		return;
	}
	int t=upper_bound(c+1,c+1+n,cnt)-c;
	for(int i=t;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(a[k]==0) dfs(k+1,cnt+1);
			else dfs(k+1,cnt);
			f[i]=0;
		}
	}
	return;
}
signed main(){
	IOS
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int flag=0;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
		if(a[i+1]==0) flag=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag==0){
		ans=1;
		for(int i=n;i>=1;i--) ans=(ans*i)%mod;
		return cout<<ans%mod<<endl,0; 
	}
	sort(c+1,c+1+n);
	dfs(1,0);
	cout<<ans%mod<<endl;
	return 0;
}
