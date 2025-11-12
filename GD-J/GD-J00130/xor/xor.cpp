#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t[305],t2[305],d,ans;
int main()
{
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		d=k^a[i];
		if(t[d]==1||d==0)
		{
			for(int j=0;j<=299;j++)
			{
				t[j]=t2[j]=0;
			}
			ans++;
		}
		else
		{
			for(int j=0;j<=299;j++)
			{
				if(t[j]==1)
				{
					t2[a[i]^j]=1;
				}
			}
			for(int j=0;j<=299;j++)
			{
				t[j]=t2[j];
				t2[j]=0;
			}
			t[a[i]]=1;
		}
	}
	cout<<ans;
	return 0;
}
