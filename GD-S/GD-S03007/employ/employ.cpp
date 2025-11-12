#include<bits/stdc++.h>
using namespace std;
long long n,m,o,s=0,a[550],b[550],f[(1<<18)+10][19],po[550],mo=998244353;
char c;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m;
	o=0;
	po[0]=1;
	for(int i=1;i<=n;i++)
	{
		po[i]=po[i-1]*i%mo;
		cin>>c;
		if(c=='1')
		{
			++o;
			a[o]=i-o;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	f[0][0]=1;
	for(int i=0,z;i<(1<<n);i++)
	{
		z=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				z++;
			}
		}
		if(z<o)
		{
			for(int j=0;j<=n&&o-j>=m;j++)
			{
				for(int x=0;x<n;x++)
				{
					if(!((i>>x)&1))
					{
						int v=(i|(1<<x));
						if(b[x]>a[z+1]+j)
						{
							f[v][j]=(f[v][j]+f[i][j])%mo;
						}
						else
						{
							
							f[v][j+1]=(f[v][j+1]+f[i][j])%mo;
						}
					}
				}
			}
		}
		
	}
	for(int i=0,z;i<(1<<n);i++)
	{
		z=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				z++;
			}
		}
		if(z==o)
		{
			for(int j=0;j<=n&&o-j>=m;j++)
			{
				//cout<<i<<' '<<j<<' '<<f[i][j]<<"\n";
				s=(s+f[i][j])%mo;
			}
		}
	}
	s=s*po[n-o]%mo;
	cout<<s;
}
