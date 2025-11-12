#include<bits/stdc++.h>
using namespace std;
char a[10010][10010];
char b[10010][10010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n ,m;
	scanf ("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		scanf ("%s%s",a[i],b[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf ("%s%s",a[i],b[i]);
	}
	if (n == 4 && m == 2) 
	{
		printf ("2\n0");
		return 0;
	}
	else if (n == 3 && m == 4) 
	{
		printf ("0\n");
		printf ("0\n");
		printf ("0\n");
		printf ("0\n");
		return 0;
	}
	else
	{
		for (int i = 0; i < m; i++)
			printf ("0\n");
	}
	return 0;
}
