#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005],b[100005]={0},sum=0,q=0,h=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			sum++;
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int sum=a[i-1];
		q=0;
			for(int j=2;j<=i;j++)
			{
				for(int m=1;m<=j;m++)
				{
					if(b[i]==0)
					{
						sum^=a[j];
						q=max(sum,q);
						if(sum==k)
						{
							cout<<q;
							return 0;
						}
					}

				}

			}
			if(sum!=k)
			{
				q=0;
			}
	}
	cout<<h;
	return 0;
}
