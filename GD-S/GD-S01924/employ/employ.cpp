#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],f[20][20][262150],idx[262150],ans;
vector<int> pc[20];
bool s[N];
inline void add(int &a,int b)
{
	a+=b;
	if(a>=mod) a-=mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		s[i]=(ch=='1');
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18)
	{
		for(int i=0;i<(1<<n);i++)
		{
			int ppc=0,x=i;
			while(x) ppc++,x-=(x&(-x));
			pc[ppc].push_back(i);
		}
		for(int i=1;i<=n;i++) idx[1<<i-1]=i;
		f[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k:pc[i])
				{
					int x=k;
					while(x)
					{
						int l=idx[x&(-x)];
//						cout<<x<<" "<<l<<endl;
						if(!s[i])
						{
							add(f[i][j][k],f[i-1][j][k^(1<<l-1)]);
							x^=(1<<l-1);
							continue;
						}
						if(j<i&&i-1-j>=c[l]) add(f[i][j][k],f[i-1][j][k^(1<<l-1)]);
						if(j>0&&i-1-(j-1)<c[l]) add(f[i][j][k],f[i-1][j-1][k^(1<<l-1)]);
						x^=(1<<l-1);
					}
				}
			}
		}
		for(int i=m;i<=n;i++) add(ans,f[n][i][(1<<n)-1]);
		cout<<ans;
		return 0;
	}
}
/*
18 10
111101111010111101
1 1 4 5 1 4 1 9 1 9 8 10 1 9 1 4 5 1

*/
