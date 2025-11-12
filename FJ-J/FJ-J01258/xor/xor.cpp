#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5002;
const int M=1048579;
int a[N];
int xo[N];
int m[M];
int n,k;
signed main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;

	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}

	for(int i=1;i<=n;i++)
	{
		xo[i]=(xo[i-1] xor a[i]);
		m[xo[i]]++;
	}
	m[0]=1;
	int ans=0,end=0;
	for(int i=1;i<=n;i++)
	{
		int c=xo[i] xor k;
		if(m[c]==0)continue;
		for(int j=i-1;j>=end;j--)
		{
			if(xo[j]==c)
			{
				end=i;
				ans++;
				
			}
		}
	}
	cout<<ans;
	return 0;
}
