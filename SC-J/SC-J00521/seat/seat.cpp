#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define maxn 1000005
using namespace std;
int a[maxn],s[1005][1005];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=1,l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	l=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				s[i][j]=a[k];
				if(a[k]==l)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				s[i][j]=a[k];
				if(a[k]==l)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
