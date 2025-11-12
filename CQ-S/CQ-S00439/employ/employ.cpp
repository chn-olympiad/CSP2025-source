#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[505];
int c[505];
const int mod=998244353;
int p[15];
int bj[15];
int ans=0;
void dfs(int now){
	if(now==n+1){
		int he=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0 || he>=c[p[i]]){
				he++;
				continue;
			}
			cnt++;
		}
		if(cnt>=m) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			bj[i]=1;
			p[now]=i;
			dfs(now+1);
			bj[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int Flag=0;
	for(int i=1;i<=n;i++){
		char t;
		cin>>t;
		a[i]=(int)(t-'0');
		if(a[i]==0){
			Flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(Flag==0){
		int ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
