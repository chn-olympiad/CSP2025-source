#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

int n , m;
int a[N];

struct node{
	int x , y;
}s[N];

bool cmp(int a , int b)
{
	return a >= b;
}

int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1 ; i <= n * m ; i ++)
	{
		cin>>a[i];
	}
	int t = a[1];
	sort(a + 1 , a + n * m + 1 , cmp);
	int x = 0 , y = 1;
	bool fx = 0;
	for(int i = 1 ; i <= n * m ; i ++)
	{
		if(fx == 0 && x + 1 <= n)
		{
			x++;
			s[a[i]].x = x;
			s[a[i]].y = y;
		}
		else if (fx == 0 && x + 1 > n)
		{
			fx = 1;
			y++;
			s[a[i]].x = x;
			s[a[i]].y = y;
		}
		else if(fx == 1 && x - 1 >= 1)
		{
			x--;
			s[a[i]].x = x;
			s[a[i]].y = y;			
		}
		else if (fx == 1 && x - 1 < 1)
		{
			y++;
			fx = 0;
			s[a[i]].x = x;
			s[a[i]].y = y;		
		}
	}
	cout<<s[t].y<<' '<<s[t].x;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
