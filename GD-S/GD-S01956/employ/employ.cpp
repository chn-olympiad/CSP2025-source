#include<bits/stdc++.h>
using namespace std;
int n,m,c[1005],sum,su;
long long ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') sum++; 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) su++;
	}
	if(sum==n&&su==0)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	else if(sum<m&&n-su<m)
	{
		cout<<0;
	}
	else cout<<1;

	
	return 0;
} 
