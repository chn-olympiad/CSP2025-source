#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10,inf=1e18,mod=1e9+7;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
int n,m,cnt=0;
pii t[maxn];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) t[i].first=read(),t[i].second=i;
	sort(t+1,t+n*m+1);
	reverse(t+1,t+n*m+1);
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++)
			{
				if(t[++cnt].second==1)
				{
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(t[++cnt].second==1)
				{
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
