#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[101],x,b[11][11],tot,t;
bool cmp(int a,int b)
{
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=a[++t];
				if(b[i][j]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				b[i][j]=a[++t];
				if(b[i][j]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
