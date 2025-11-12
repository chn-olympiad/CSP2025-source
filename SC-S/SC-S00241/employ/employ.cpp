#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50,mod=998244353;
string a;
int cnt2[N];
int vis[N],ans=0,n,m;
void dfs(int x,int cnt){//当前位置    有 cnt 个人通过了
	if(n-x+1+cnt<m) return; 
	if(x==n+1){
		if(cnt>=m) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			int o=x-cnt-1;
			vis[i]=1;
			int l=(cnt2[i]>o);
			dfs(x+1,cnt+((a[x-1]=='1') && l==1));
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int sum=0;
	for(int i=0;i<n;i++) sum+=(a[i]=='1');
	for(int i=1;i<=n;i++) cin>>cnt2[i];
	if(sum<m){
		cout<<0<<endl;
		return 0;
	}
	if(m==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod<<endl;
		return 0;
	}
	if(m==n){
		cout<<1<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans%mod<<endl;
}