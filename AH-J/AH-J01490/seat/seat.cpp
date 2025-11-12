# include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n,m,a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n*m; i++) scanf("%d",&a[i]),a[i] = -a[i];
	int t = a[1],x;
	sort(a+1,a+1+n*m);
	for (int i = 1; i <= n*m; i++) if (a[i] == t) x = i;
	int h1 = x % n == 0 ? n : x % n;
	int h2 = (x+n-1)/n;
	printf("%d %d",h2,h2 % 2 == 1 ? h1 : n - h1 + 1);
	fclose(stdin);
	fclose(stdout);
}
