#include <bits/stdc++.h>
using namespace std;
int a[5001];
unsigned long long sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		long long cn1=1;
		for(int j=1;j<=n;j++)
			cn1*=j;
		long long cn2=1;
		for(int j=1;j<=i;j++)
			cn2*=j;
		long long cn3=1;
		for(int j=1;j<=(n-i);j++)
			cn3*=j;
		if(i==n)
			cn3=1;              
		long long cn=cn1/(cn2*cn3);
		sum=(sum+cn)%998244353;
	}
	cout<<sum;
	return 0;
}

