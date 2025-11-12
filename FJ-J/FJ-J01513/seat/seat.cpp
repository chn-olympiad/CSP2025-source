#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n,m;
int l[100][100];
int s[5000000];
int aa=0;
int st[100];
int nnn=0;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
		if(i==1)
			aa=s[i]; 
	}
		
		
	sort(s+1,s+n*m+1,cmp);
	

	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			st[j]=s[nnn+j];
		}
		nnn=nnn+n;
		if(i%2==0)
			sort(st+1,st+1+n);
		
		for(int j=1;j<=n;j++)
		{
			l[j][i]=st[j];
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(l[i][j]==aa)
			{
			
				cout<<j<<" "<<i;
				return 0; 
			}
		}
	}

		
}
