#include <bits/stdc++.h>
using namespace std;
const int N=1005;
 
int n, m, a[N], tot, p;
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m), tot=n*m;
	for (int i=1; i<=tot; i++) scanf("%d", &a[i]);
	
	p=a[1];
	sort(a+1, a+1+tot, cmp);
	
	int px=1, py=1, ad=1;
	for (int i=1; i<=tot; i++)
	{
		if (a[i]==p) printf("%d %d", py, px);
		if (ad==1)
		{
			if (px<n) px++;
			else py++, ad=-1;
		}
		else
		{
			if (px>1) px--;
			else py++, ad=1;
		}
	}
	return 0;
} 
/*
2 2
99 100 97 98

*/
