#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=1005;
ll n,m,a[maxn],r,f[maxn][maxn],cnt=0;
inline void fre()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
inline bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	IOS
	fre();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=a[++cnt];
				if(f[i][j]==r) 
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				f[i][j]=a[++cnt];
				if(f[i][j]==r)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
