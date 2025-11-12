#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int a;
	int tmp=0;
	cin >> a;
	int cnt=1;
	for(int i = 1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1 && j==1)continue;
			cin >> tmp;
			if(tmp>a)
			{
				cnt++;
			}
		}
	}
	int f[2]={1,-1},l=0;
	int x=1,y=1;
	int num=1;
	while(num < cnt)
	{
		//cout << x << " " << y << "\n";
		if(y+f[l]>m || y+f[l]<1)
		{
			x++;
			y+=f[l];
			l=1-l;
		}
		y+=f[l];
		num++;
	}
	cout << x << " " << y;
	return 0;
}
