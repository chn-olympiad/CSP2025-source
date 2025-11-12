#include<bits/stdc++.h>
using namespace std;
int s[100010];
int a[100010];
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n, m;
	scanf ("%d%d",&n,&m);
	for (int i = 0; i < n*m; i++)
	{
		scanf ("%d",&a[i]);
	}
	int ans = a[0];
	sort(a,a+n*m);
	int t = 0;
	for (int i = n*m-1; i >= 0; i--)
	{
		s[t++] = a[i];
	}
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[(i*n)+j] == ans)
			{
				if (f == 0)
				{
					printf ("%d %d",i+1,j+1);
					return 0;
				}
				else
				{
					printf ("%d %d",i+1,m-j);
					return 0;
				}
			}
		}
		if (f == 0) f = 1;
		else f = 0;
	}
	return 0;
}
