#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("clude.in","r",stdin);
	freopen("clude.out","w",stdout);
	int t,n,d=0,a[1001];
	cin>>t>>n;
	for(int i=0;i<=n;i++)
	{
		i=a[i+1];
		d=a[i+1]+a[i];
	}
	cout<<d;
	flose(stdin);
	flose(stdout);
	return 0;
}

