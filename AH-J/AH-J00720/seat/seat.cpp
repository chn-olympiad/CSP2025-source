#include<bits/stdc++.h>
using namespace std;
int a[405] , s[15][15] , rp , qaq;
bool cmp(int x , int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int len = n * m;
	cin >> qaq;
	a[1] = qaq;
	for(int i = 2 ;  i <= len ; i++)
		cin >> a[i];
	sort(a + 1 , a + len + 1 , cmp);
	for(int i = 1 ; i <= m ; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1 ; j <= n ; j++)
			  	s[i][j] = a[++rp];
		
		}
		else
		{
			for(int j = n ; j >= 1 ; j--)
				s[i][j] = a[++rp];
		}
	}
	int flag = false;
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
			if(s[i][j] == qaq)
			{
				cout << i << " " << j;
				flag = true;
				break;
			}
		if(flag)
			break;
	}
	return 0;
}
