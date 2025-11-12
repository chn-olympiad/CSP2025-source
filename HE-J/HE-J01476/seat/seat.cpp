#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+2,a+n*m+1,cmp);
	if(x>a[2])
	{
		cout<<"1 1";
		return 0;
	}
	if(x<a[n*m])
	{
		if(m%2)cout<<m<<' '<<n;
		else cout<<m<<' '<<1;
		return 0;
	}
	int i=2,j=1,nw=2;
	for(;j<=m;j++)
	{
		if(j%2)
		{
			for(i=j==1?2:1;i<=n;i++)
			{
				if(a[nw]>x&&x>a[nw+1])
				{
					cout<<j<<' '<<i;return 0;
				}
				nw++;
			}
		}
		else
		{
			for(i=n;i>=1;i--)
			{
				if(a[nw]>x&&x>a[nw+1])
				{
					cout<<j<<' '<<i;return 0;
				}
				nw++;
			}
		}
	}
	return 0;
}
