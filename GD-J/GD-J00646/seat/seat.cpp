#include <bits/stdc++.h>
using namespace std;

int a[225];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,id,cur=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cur++;
			cin >> a[cur];
			if (cur==1) R=a[cur];
		}
	}
	sort(a+1,a+cur+1,cmp);
	for (int i=1;i<=cur;i++) if (a[i]==R) id=i;
	int x=1,y=1;
	while (--id)
	{

		if (y%2==1) 
		{
			if (x==n) y++;
			else x++;
		}
		else if (y%2==0)
		{
		    if (x==1) y++;
			else x--;
		}
	}
	cout << y << " " << x;
	return 0;
 } 
