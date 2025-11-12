#include <bits/stdc++.h>
using namespace std;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long sum=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	//A
	for(int i=n-m+1;i<=n;i++)
	{
		sum*=i;
	}
	cout<<sum%998224353;
}
