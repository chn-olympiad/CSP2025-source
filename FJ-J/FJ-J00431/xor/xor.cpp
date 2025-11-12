#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],s,d,b[100005],f[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			a[i]=-1;
			s++;
		}
		else if(a[i]>0)
		{
			b[++d]=a[i];
		}
	}
	for(int i=1;i<d;i++)
	{
		if((b[i]^b[i+1])==k)
		{
			s++;
		}
		for(int j=1;j<i;j++)
		{
			f[j]=b[j]^b[j+1];
		}
	}
	cout<<s;
	return 0;
}
			
