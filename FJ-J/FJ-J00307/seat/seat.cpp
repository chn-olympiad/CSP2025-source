#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105],x=1,y=1,n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>b[i];	
	}
	int r=b[1];
	sort(b+1,b+len+1);
	int k=len;
	while(k!=0)
	{
		a[x][y]=b[k];
		k--;
		if(x==n&&y%2==1||y%2==0&&x==1)
		{
			y++;
		}
		else if(y%2==1&&x!=m)
		{
			x++;
		}
		else if(y%2==0&&x!=1)
		{
			x--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}


	return 0;
}

