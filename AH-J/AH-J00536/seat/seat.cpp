#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int xa;
int x[105];
int y[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>x[i];
	xa=x[1];
	sort(x+1,x+n*m+1,cmp);
	for(int i=0;i<m;i++)
	{
		if((i&1)==0)
			for(int j=i*n+1;j<=i*n+n;j++)
				y[j-i*n][i+1]=x[j];
		else
			for(int j=i*n+n;j>=i*n+1;j--)
				y[j-i*n][i+1]=x[2*i*n+n+1-j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(y[i][j]==xa)
			//{
				cout<<j<<" "<<i<<"\n";
				//return 0;
			//}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<y[i][j]<<" ";
		cout<<"\n";
	}*/
	
	return 0;
}
/*
Luogu id=1383031
#Shang4Shan3Ruo6Shui4
//freopen(".in","r",stdin);
// freopen("
*/
