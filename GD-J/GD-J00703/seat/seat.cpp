#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 110;
int a[maxn];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int my = a[1];
	sort(a+1, a+1+n*m, greater<int>());
	int mypos = 0;
	for(int i=1;i<=n*m;i++) if(a[i] == my) mypos = i;
	int col = mypos/n + 1;
	int d = mypos % n;
	if(d==0)
	{
		col--;
		d=n;
	}
	if(col%2==0) d=n-d+1;
	cout<<col<<' '<<d;
	fclose(stdin);
	fclose(stdout);
} 
