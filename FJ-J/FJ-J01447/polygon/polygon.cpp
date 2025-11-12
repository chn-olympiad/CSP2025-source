#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+5;
const int mod=998244353;
int n,ans,cnt;
int a[maxn];
int s[maxn];
bool vis[maxn];
void dfs(int nn,int ceng,int now,int bz,int mx){
	if(ceng-1==nn){
		int sum=0;
		for(int i=1;i<=nn;i++) sum+=s[i];
		if(sum>bz){
			cnt++;
		}
	}
	for(int i=now;i<=mx;i++){
		if(!vis[i]){
			vis[i]=true;
			s[ceng]=a[i];
			dfs(nn,ceng+1,i,bz,mx);
			s[ceng]=0;
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int k=n;k>=n-3+1;k--){
		for(int kk=2;kk<=k-1;kk++){
			cnt=0;
			for(int l=1;l<=n;l++) vis[l]=false;
			dfs(kk,1,1,a[k],k-1);
			ans+=cnt;
			ans%=mod;
		}
	}
	cout<<ans%mod;
}
