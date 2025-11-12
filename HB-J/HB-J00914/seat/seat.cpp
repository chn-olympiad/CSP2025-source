#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m,id=1;
int h=0;
int s[105],sx=1,sy=0;
bool cmp(int o,int k)
{
	
	return o>k;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	int f=0;
	int k=n*m;
	for(int i=1;i<=k;i++)
	{
		
			
		cin>>s[i];
		if(f==0)
		{
			f=s[i];
		}
	}
	sort(s+1,s+k+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(h==0)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=s[id++];
			}
			h=1;
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[j][i]=s[id++];
			}
			h=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=m;j++)
		{
			
			if(a[i][j]==f)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
		
	
	}
	return 0;

}
