#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int c[100000];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int sum=1;
	for(int i=n;i>=1;i--)
	{
		sum*=i;
	}
	cout<<sum%998024353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
