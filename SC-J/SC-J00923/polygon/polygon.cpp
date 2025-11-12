#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n;
int a[100005];
int c[5005][5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=5000;i++)c[i][0]=1;
	for(int i=0;i<=5000;i++)c[i][i]=1;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j]%mod;
	int ans=0;
	for(int i=3;i<=n;i++)
		ans=ans+c[n][i]%mod;
	cout<<ans;
	
	return 0;
}