#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
		cin >> a[i];
	int mx=0;
	for (int i=2;i<=n*m;i++)
		if (a[i]>a[1])
			mx++;
	int x=mx/n+1,y=mx%n;
	if (x%2==1)
		cout << x << " " << y+1;
	else
		cout << x << " " << n-y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
