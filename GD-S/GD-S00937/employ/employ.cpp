#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
int n,m,cnt0,cnt1;
string s; 
int a[501];
bool b[501];
signed main ()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		b[i+1]=s[i]-'0';
	//	cout<<b[i+1]<<' ';
		if(b[i+1])cnt1++;
		else cnt0++;
	}
	if(cnt1<m)
	{
		cout<<0;
		return 0;
	} 
	if(cnt0==0)//льеп 
	{
		int ans=1;
		for(int i=0;i<n;i++)
		{
			ans=(ans*(n-i))%mod;
				
		}
		cout<<ans<<endl;
		return 0;
	}
	int ans=1;
	for(int i=0;i<n;i++)
	{
		ans=(ans*(n-i))%mod;	
	}
	cout<<ans;
	return 0;
//	if(m==1)
//	{
//		if(b[1]==1)
//		{
//			
//		}
//		else
//		{
//			
//		}
//	}
//	return 0;
}
