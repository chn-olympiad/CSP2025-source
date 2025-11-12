#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,s=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(a[1]+a[2]+a[3]>=2*a[3])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
