#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],f[N],s[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)cnt++,f[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[j]=f[j];
			s[j]+=s[j-1];
		}
		int sum=0,z=i;
		for(int j=i;j<=n;j++)
		{
			if(s[j]-s[z-1]!=0)break;
			sum=(sum^a[j]);
			if(sum==k)
			{
				z=j+1;
				sum=0;
				cnt++;
			}
		}	
		for(int j=i;j<z;j++)
		{
			f[j]=1;
		}
	} 
	cout<<cnt;
	return 0;	
}
