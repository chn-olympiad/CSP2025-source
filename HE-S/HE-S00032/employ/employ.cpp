#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll sum=1,n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		sum*=i;
	}
	cout<<sum;
	return 0;
}
