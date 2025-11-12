#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],x,y,a,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	a=s[1],cnt=n*m;
	sort(s+1,s+n*m+1);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[cnt]==a)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				cnt--;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(s[cnt]==a)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}
