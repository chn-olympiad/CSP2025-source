#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int use[100005],ans;
int n,m,f=1,cnt;
string s;
int a[1000005];
int b[1000005];
void dfs(int id,int k){
	if(id>n){
		if(n-k>=m)ans=(ans+1)%mod;
		return;
	}
	if(n-k<m)return;
	for(int i=1;i<=n;i++){
		if(use[i]==0){
			use[i]=1;
			if(k>=b[i]||a[id]==0)dfs(id+1,k+1);
			else dfs(id+1,k);
			use[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)a[i+1]=s[i]-'0',f=min(f,a[i+1]);
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0)cnt++;
	}
	if(m==1&&n>20){
		int res=1;
		for(int i=1;i<=n;i++)res=(res*i)%mod;
		cout<<res;
		return 0;
	}
	if(m==n&&f==0){
		cout<<0;
		return 0;
	}
	if(f==1&&n>20){
		int res=1;
		for(int i=2;i<=n-cnt;i++)res=(res*i)%mod;
		cout<<res;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}/*
22:14
23:15
10 5
1101111011
3 6 0 4 2 1 2 5 4 3 3

*/
