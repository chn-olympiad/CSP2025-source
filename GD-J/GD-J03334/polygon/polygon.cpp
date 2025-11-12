#include<bits/stdc++.h>
using namespace std;
const int N=5020;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int u=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) u=1;
	}
	if(n<3) cout<<"0";
	if(n==3)
	{
		int z=0,s=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>z) z=a[i];
			s+=a[i];
		}
		if(2*z>s) cout<<"1";
	}
	if(u==0)
	{
		
		long long ans=0;
		long long m=0;
		for(long long i=1;i<=n;i++) if(a[i]==0) m+=1; 
		for(long long i=3;i<=n-m;i++)
		{
			long long h=1,g=1;
			for(long long j=n-m;j>n-m-i;j--) h*=j;
			for(long long j=i;j>=1;j--) g*=j;
			long long y=h/g;
			ans+=y;
		}
		cout<<ans%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
