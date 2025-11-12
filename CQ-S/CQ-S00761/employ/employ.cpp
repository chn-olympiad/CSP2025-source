#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=555;
const int mod=998244353;
int n,m;
long long f[N],ans;
string s;
int c[N],vis[N];
long long dfs(int pos,int sum){
	if(sum>=m){
		return f[n-pos+1];
	}
	if(pos>n){
		return 0;
	}
	long long res=0;
	int lose=pos-sum-1;
	if(sum+n-pos+1<m)return 0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(lose>=c[i]){
			vis[i]=pos;
			res=(res+dfs(pos+1,sum))%mod;
			vis[i]=0;
		}else if(s[pos]=='0'){
			vis[i]=pos;
			res=(res+dfs(pos+1,sum))%mod;
			vis[i]=0;
		}else{
			vis[i]=pos;
			res=(res+dfs(pos+1,sum+1))%mod;
			vis[i]=0;
		}
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*i%mod;
		cin>>c[i];
	}
	cout<<dfs(1,0);
}
