#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
string s;
int c[501];
long long fanan=0;
int main()
{
	freopen("employ.in","r",stdin);
	 freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	if(n==m)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]-'0') 
			{
				cout<<0;
				return 0;
			}
		}
		fanan=1;
		for(int i=n;i>=1;i--)
		{
			fanan*=i;
			fanan=fanan%998244353;
		}
		cout<<fanan;
		return 0;
	}
	return 0;
}
