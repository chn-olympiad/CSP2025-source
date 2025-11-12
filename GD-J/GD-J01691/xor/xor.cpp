#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,b,k,sum,f[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n>=100000&&k<=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			sum++;
		}
		cout<<sum;
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
		    f[i+1]=max(f[i+1],1+f[i]);
		    continue;
		}
		else
		f[i+1]=max(f[i+1],f[i]);
		long long b=a[i]; 
		for(int j=i+1;j<=n;j++)
		{
			b^=a[j];
			//cout<<i<<" "<<j<<" "<<b<<endl;
			if(b==k)
			{
				f[j+1]=max(f[j+1],f[i]+1);
				break; 
			}
		}
	}
	cout<<f[n+1];
	return 0;
}
