#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,mod=998244353;
bool vis[N];
int n,m,len,sum[N],c[N],sum0,cnt,ans;
string s;
void dfs(int k){
	if(k>m){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&sum[k-1]<c[i]){
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
void work(int k){
	if(k>m){
		cnt++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&sum[k-1]>=c[i]){
			vis[i]=1;
			work(k+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(i>0)sum[i]=sum[i-1];
		if(s[i]=='0'){
			sum[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]){
			sum0++;
		}
	}
	if(n-sum0<m){
		cout<<"0";
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	ans=1;
	for(int i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}
	if(m==1){
		work(1);
		ans-=cnt;
	}
	cout<<ans;
	return 0;
} 
