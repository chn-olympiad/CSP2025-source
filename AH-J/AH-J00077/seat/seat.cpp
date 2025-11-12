#include<bits/stdc++.h>
using namespace std;
int a[110],b[110][110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int k=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				b[i][j]=a[cnt];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				b[i][j]=a[cnt];
			}
		}
	}
	for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==k)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
    return 0;
}
