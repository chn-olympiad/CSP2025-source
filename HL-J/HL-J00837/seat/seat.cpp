#include<bits/stdc++.h>
using namespace std;
int c[15][15];
int a[125];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,cnt=0;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int line=1;line<=m;line++)
	{
		if(line%2==0)
		{
			for(int row=n;row>=1;row--)
			{
				cnt++;
				c[line][row]=a[cnt];
				if(c[line][row]==x)
				{
					cout<<line<<' '<<row;
				}
			}
		}
		else
		{
			for(int row=1;row<=n;row++)
			{
				cnt++;
				c[line][row]=a[cnt];
				if(c[line][row]==x)
				{
					cout<<line<<' '<<row;
				}
			}
		}
	}
	return 0;
}
