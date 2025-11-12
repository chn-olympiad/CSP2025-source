#include<bits/stdc++.h>
#define N 998244353
using namespace std;
int n,m,c[505];
long long ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	ans=1ll;
	for(int i=1;i<=n;i++)
	ans=ans%N*1ll*i%N;
	cout<<ans;
	return 0;
} 
