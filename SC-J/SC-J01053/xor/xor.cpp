#include<bits/stdc++.h>
using namespace std;
#define int long long
int A[500005];
bool B[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(A[i]==0)
			{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(A[i]==m)
			{
				B[j]=1;
				cnt++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			int t=0;
			for(int k=i;k<=n;k++)
			{
				t^=A[i];
				if(B[k]==1) break;
				if(t==m)
				{
					cnt++;
					for(int k=j;k<=n;k++)
					{
						B[k]=1;
					}
				}
			}
			
		}
	}
	cout<<cnt;
	return 0;
}
