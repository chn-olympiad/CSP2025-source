#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int c[1005][1005];
int n,m,ans=1;
int a[10005];
string s;
void init(){
	for(int i=1;i<=n;i++) c[i][i]=1,c[i][1]=i;
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=((ans%mod)*(i%mod))%mod;
	}
	cout<<ans%mod;
	return 0;
}
