#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[505],c[505];
const int mod = 998244353;


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(c[i]>c[i+1]){swap(c[i],c[i+1]);}
		}
	}
	
	
	
	return 0;
}
