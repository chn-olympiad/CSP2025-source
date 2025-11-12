#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=m+1;i<=n;i++)
	{
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
