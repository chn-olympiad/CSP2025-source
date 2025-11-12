#include<bits/stdc++.h>
using namespace std;
int c[600];
const long long MOD=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int nn=n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			nn--;
		}
	}
	long long ji=1;
	for(int i=nn;i>=1;i--)
	{
		ji=(ji*i)%MOD;
	}
	cout<<ji;
	return 0;
}
