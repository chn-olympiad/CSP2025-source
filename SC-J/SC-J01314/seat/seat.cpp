#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];
int an,am;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int x = a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == x)
		{
			if(i == 1)
			{
				am = 1,an = 1;
				break;
			}
			am = (i-1)/n+1;
			int y = i;
			y -= (am-1)*n;
			if(am%2)
			{
				an = y;
			}
			else
			{
				an = n-y+1;
			}
			break;
		}
	} 
	cout << am << " " << an;  
	return 0;
}