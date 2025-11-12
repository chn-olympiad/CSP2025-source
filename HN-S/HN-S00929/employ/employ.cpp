//16 39 2/2 8pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=500+5,mod=998244353;
int n,m,s[N],c[N],t[N],ans=0,sum[N],f[N];
bool a[N],vis[N];
void dfs(int cur,int cnt){
	if(cnt>=m){
		ans+=f[n-cur+1];
		ans%=mod;
		return;
	}
//	cerr<<"@"<<cnt<<endl;
	if(cur==n+1){
		return;
	}
	if(sum[cur]+cnt<m){
//		cerr<<"!"<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
//			cerr<<"#";
//			for(int i=1;i<cur;i++){
//				cerr<<" ";
//			}
//			cerr<<i<<"\t$"<<(cnt+(c[i]>cnt-cur+1&&a[cur]))<<endl;
			dfs(cur+1,cnt+(c[i]>cur-cnt-1&&a[cur]));
			vis[i]=false;
		}
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c=='1';
		f[i]=f[i-1]*i%mod;
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

