#include<bits/stdc++.h>
using namespace std;
int n , m;
const int N = 1e6 + 10;
int a[N] , sco , cnt = 1;
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	scanf("%d" , &sco);
	a[1] = sco;
	for(int i = 2 ; i <= n * m ; i ++)
	{
		scanf("%d" , &a[i]);
		if(a[i] > sco)
			cnt ++;
	}
	int l = cnt / n;
	//cout << cnt << endl;
	if(cnt % n == 0)
	{
		printf("%d %d" , l , n);
	}
	else
	{
		printf("%d " , l + 1);
		if(l % 2 == 0)
		{
			int x = cnt % 2;
			if(x == 0)
				printf("%d" , n);
			else
				printf("%d" , cnt % n);
		}
		else
			printf("%d" , n - (cnt % n) + 1);
	}
	return 0;
}
//2 2
//99 100 97 98

