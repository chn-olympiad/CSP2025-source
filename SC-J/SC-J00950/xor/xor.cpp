#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1145],x[1145][1145],ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		x[i][i]=a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			x[i][j]=x[i][j-1]^x[j][j];
		}
	}
	int lasi,lasj;
	bool las=0;
	for(int i=n;i>=1;--i)
	{
		for(int j=i;j<=n;++j)
		{
			if(x[i][j]==k)
			{
				if(las==0)
				{
					ans++;
					las=1;
					lasi=i,lasj=j;
					break;
				}
				else
				{
					if(j>=lasj) continue;
					else
					{
						ans++;
						lasi=i,lasj=j;
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//为什么把题出这么难FUCK CCF