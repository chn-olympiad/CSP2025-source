#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
		cin >> a[i];
	int s = a[1];
	sort(a+1,a+1+n*m);
	int x;
	for(int i=1; i<=n*m; i++)
		if(a[i] == s)
		{
			x = n*m-i+1;
			break;
		}
	int r, c;
	c = (x-1)/n+1;
	if(c%2 != 0)
		r = (x-1)%n+1;
	else
		r = n-((x-1)%n+1)+1;
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
