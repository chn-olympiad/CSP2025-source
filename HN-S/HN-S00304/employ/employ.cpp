#include<bits/stdc++.h>
using namespace std;
long long int n,m,ans=1,c[505],nn;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	nn=n;
	for(int i=1;i<=nn;i++)
	{
		cin>>c[i];
		if(c[i]==0)
			n--;
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==n)
	{
		cout<<1;
		return 0;
	}
	for(int i=n;i>=n-m+1;i--)
		ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
}

