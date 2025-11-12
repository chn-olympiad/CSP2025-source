/*
100 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e3;
int n,m;
int a[MAXN];
int R;
int ansx,ansy;
inline bool cmp(int A,int B)
{
	return A>B;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	R=a[1];
	stable_sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(R==a[i])
		{
			for(int j=1;j<=m;++j)
			{
				if(j%2==1)
				{
					for(int k=1;k<=n;++k)
						if(a[(j-1)*n+k]==R)
						{
							ansx=j,ansy=k;
							break;
						}
				}
				else
				{
					for(int k=n;k>=1;--k)
						if(a[(j-1)*n+(n-k+1)]==R)
						{
							ansx=j,ansy=k;
							break;
						}
				}
			}
			cout<<ansx<<" "<<ansy;
			return 0;
		}
	}
	return 0;
}