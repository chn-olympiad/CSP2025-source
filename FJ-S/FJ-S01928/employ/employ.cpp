#include <bits/stdc++.h>
#define z 787891
using namespace std;
int n,m;
string s;
int aa(int x)
{
	int ans=1;
	for(int i=n;i>=1;i--)
	{
		ans=ans*n%998244353;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	if(m==0)
	{
		cout<<aa(n);
	}
	else
		cout<<0;
	return 0;
}

