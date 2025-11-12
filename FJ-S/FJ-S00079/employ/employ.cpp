#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int s[600],c[600];
bool gt[100];
int cnt=0,th=0;
int c0=0;
int jc(int x)
{
	int ans=1;
	for(int i=1;i<=x;i++)
	{
		ans*=i;
		ans%=mod;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		c0+=(c[i]==0);
	}
	//int ans=1;
	if(n-c0>=m)cout<<jc(n);
	else if(n-c0+1==m)cout<<c0*jc(n-c0);
	else cout<<0;
	return 0;
}
