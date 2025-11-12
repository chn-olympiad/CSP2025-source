#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+5,mod=998244353;
int a[N],sum[N];
int n,ans;
int b[N],cnt;

void dfs(int lst,int nm,int nc,int nw,int maxw){
	if(nc>=nm){
		if(nw>maxw){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(sum[n]-sum[lst-1]+nw<maxw){
			return;
	}
	for(int i=lst+1;i<=n;i++){
		b[++cnt]=i;
		dfs(i,nm,nc+1,nw+a[b[cnt-1]],a[i]);
		b[cnt]=0;
		cnt--;
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0,0);		
	}
	cout<<ans%mod;
	return 0;
}
