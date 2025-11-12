#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
	ll ret = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -f : 1) ,ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' ,ch = getchar();
	return ret * f;
}

int n ,m;
const int N = 20;
int a[N * N];

int main()
{
	freopen("seat.in" ,"r" ,stdin);
	freopen("seat.out" ,"w" ,stdout);
	n = read() ,m = read();
	
	for (int i = 1;i <= n * m;i++) a[i] = read();
	int num = a[1];
	
	sort(a + 1 ,a + 1 + n * m); reverse(a + 1 ,a + 1 + n * m);
	
	for (int i = 1;i <= n * m;i++)
		if (a[i] == num)
		{
			int r = (i + n - 1) / n ,c = (i % n == 0 ? m : i % n);
			if (r % 2 == 0) c = m - c + 1;
			printf("%d %d\n",r ,c);
			break;
		}
	
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/

