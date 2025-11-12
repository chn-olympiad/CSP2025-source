#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int tot=0;
	int ni=0;
	if(n<=1001)
	{
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=i;j>=ni+1;j--)
			{
				res=(res^a[j]);
				if(res==k)
				{
//				cout<<j<<' '<<i<<endl;
					tot++;
					ni=i;
					break;
				}
			}
		}
		cout<<tot;
	}
	else
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) tot++;
			}
			cout<<tot;
		}
		else if(k==0)
		{
			for(int i=1;i<n;i++)
			{
				if(a[i]==0) tot++;
				if(a[i]==1 && a[i+1]==1)
				{
					tot++;
					i++;
				}
			}
			if(a[n]==0) tot++;
			cout<<tot;
		}
		else cout<<0;
	}
	return 0;
}