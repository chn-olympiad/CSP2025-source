#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
using namespace std;
const int N = 1e4+5;
int n, m;
int a[N];
int cnt;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d",&n, &m);
	For(i, 1, n*m)
		scanf("%d",&a[i]);
	For(i, 2, n*m)
		cnt += (a[i]>a[1]);
//	printf("%d ",cnt);
	int tmp = cnt/n+1; 
	printf("%d ",tmp);
	if(tmp%2) printf("%d",cnt%n+1);
	else printf("%d",n-cnt%n);
	return 0;
}

