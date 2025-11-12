#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long s=1;
	for(int i=n;i>=1;i--)
	{
		s*=i;
		s%=998244353;
	}
	cout<<s;
	return 0;
}
