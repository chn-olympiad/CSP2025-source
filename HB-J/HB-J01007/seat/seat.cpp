#include <bits/stdc++.h>
using namespace std;
int n,m,p,cnt=1;
struct yyy
{
	int id;
	int z;
}pvp[105];
int dn[15][15];
bool cmp(yyy x,yyy y)
{
	return x.z>y.z;
}
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		pvp[i].id=i;
		cin>>pvp[i].z;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i&1)
			{
				dn[j][i]=cnt++;
			}
			else
			{
				dn[n-j+1][i]=cnt++;
			}
		}
	}
	
	sort(pvp+1,pvp+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(pvp[i].id==1)
		{
			p=i;
			break;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dn[i][j]==p)
			{
				cout<<j<<" "<<i;
				exit(0);
			}
		}
	}
	return 0;
}
/*
 * 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 8 =2 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
 * 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 8 =2 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
*/
