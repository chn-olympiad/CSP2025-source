#include<bits/stdc++.h>
using namespace std;
long long x=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x=(x*i)%998244353;
	}
	cout<<x;
}
