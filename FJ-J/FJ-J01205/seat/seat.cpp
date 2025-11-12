#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],ans,num,d=1,cnt=1,s[15][15];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int x,y;
	x=y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s[i][j]=-1;
		}
	}
	s[1][1]=a[1];
	for(int i=1;i<=m;i++)
	{
		while(x+d<=n&&x+d>=0&&s[x+d][y]==-1)
		{
			cnt++;
			x=x+d;
			s[x][y]=a[cnt];
		
		}
		y+=1;
		d*=-1;
		s[x][y]=a[++cnt];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]==ans)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}