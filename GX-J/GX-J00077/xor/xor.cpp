#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
	{
		
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0&&b[i]==0)
			{
				s++;
				b[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1]&&b[i]==0&&b[i+1]==0)
			{
				s++;
				i=i+1;
				b[i]=1;
				b[i+1]=1;
			}
		}
	}
	else if(k==1)
	{
		
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&b[i]==0)
			{
				s++;
				b[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1]&&b[i]==0&&b[i+1]==0)
			{
				s++;
				i=i+1;
				b[i]=1;
				b[i+1]=1;
			}
		}
	}
	cout<<s;
	return 0;
}
