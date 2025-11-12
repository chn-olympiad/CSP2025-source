#include<bits/stdc++.h>
using namespace std;
int c[19999];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k,kk=0;
	string s;
	cin>>n>>m;
	
	k=n;
	cin>>s;
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			k--;
			kk++;
		}
	}
	
	cout<<k<<endl;
//	if(k<n)
//	{
//		cout<<0;
//		return 0;
//	}
	
	
		long long su=1;
		for(int i=1;i<=k;i++)
		{
			su=(su*i+998244353)%998244353;
		}
		cout<<su;
	
	
	
	return 0;
}
