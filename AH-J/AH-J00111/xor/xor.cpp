#include<bits/stdc++.h>
using namespace std;
	int n,a[50001],k,q[50001]={0},f[50001]={0},c,d,m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int max1=0;
		for(int j=1;j<=i;j++)
		{
			m=q[j-1]^q[i];
			if(m==k){
			max1=max(max1,1+f[j-1]);
		}
			else max1=max(max1,f[j-1]);
		}
		f[i]=max1;
	}
	int max1=0;
	for(int i=1;i<=n;i++)max1=max(max1,f[i]);
	cout<<max1;
	return 0;
}
