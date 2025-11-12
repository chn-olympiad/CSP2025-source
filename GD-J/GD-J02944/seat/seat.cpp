#include<bits/stdc++.h>
using namespace std;
int s[10000];
int s2[150][150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,z,p;
	cin>>n>>m>>s[0];p=s[0];z=n*m;
	for(int i=1;i<n*m;i++)
		cin>>s[i];
	sort(s,s+n*m);
	while(z--)
	{
		s2[x][y]=s[z];
		if(y%2==1)
		{
			if(x+1<=n)x++;
			else y++;
	    }
		else
		{
		    if(x-1>=1)x--;
		    else y++;
		}
		if(y>m){break;}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		if(s2[i][j]==p)cout<<j<<' '<<i;
	}
	return 0;
}
