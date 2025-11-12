#include<bits/stdc++.h>
using namespace std;
int M=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	int c[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int a[n+1],si=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0'){a[i]=0;si=1;}
		else a[i]=1;
	}
	sort(c+1,c+1+n);
	if(si==0)
	{
		int ans=1;
		for(int i=n;i>=n-m+1;i--)ans=(ans*i)%M;
		for(int i=m;i>=1;i--)
		{
			if(ans<i)ans+=M;
			ans/=i;
		}
		cout<<ans;
	}
	return 0;
}
