#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,tar,tmp;
int s[N],a[N][N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	tar=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				if(s[++tmp]==tar)
				{
					printf("%d %d",i,j);
					return 0;
				}
		}
		else
		{
			for(int j=n;j>=1;j--)
				if(s[++tmp]==tar)
				{
					printf("%d %d",i,j);
					return 0;
				}
		}
	}
	return 0;
}
