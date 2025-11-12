#include<bits/stdc++.h>
using namespace std;
bool flag;
int n,m,t,te,ans;
int a[1010];
int b[1010][1010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	te=a[1];
	ans+=n*m;
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=a[++t];
				if(b[i][j]==te)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				b[i][j]=a[++t];
				if(b[i][j]==te)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
