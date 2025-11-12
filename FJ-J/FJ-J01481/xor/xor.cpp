#include<bits/stdc++.h>
using namespace std;
long long n,k,res,num,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			if(a[i]>=0)
			{
				res=a[i];
			}
			else
			{
				continue;
			}
			for(int j=i+1;j<=i+l-1;j++)
			{
				if(a[j]==-1)
				{
					break;
				}
				res=res^a[j];
			}
			if(res==k)
			{
				num++;
				p+=l;
				fill(a+i,a+i+l,-1);
			}
			if(p>=n)
			{
				break;
			}
		}
		if(p>=n)
		{
			break;
		}
	}
	cout<<num;
	return 0;
}

