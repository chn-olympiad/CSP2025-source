#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
char c;
int x,n,m,ans=1,cnt;
signed main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c;
	for(int i=1;i<=m;i++){
		cin>>x;
		if(x==0) cnt++;
	}
	for(int i=1;i<=n-cnt;i++){
		ans*=i;
		ans%=mod;
	}
	for(int i=1;i<=cnt;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
