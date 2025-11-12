#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long int n,a[N],f[N],ans=0;;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
	{
		f[i]=f[i-1]+a[i];
	}
	if(f[n]>2*a[n]) ans++;
	for(int k=1;k<=n-3;k++)
	{
		for(int i=1,j=i+k-1;i<=n-k+1;i++,j++)
		{
			if(j==n)
			{
				if(f[n]-f[j]+f[i-1]>a[i-1]*2) ans++;	
			}
			else if(f[n]-f[j]+f[i-1]>a[n]*2) ans++;
			ans%=998244353;
		} 
	}
	cout<<ans%998244353<<endl;
	return 0;
}
