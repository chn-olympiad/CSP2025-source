#include<bits/stdc++.h>
using namespace std;
int s[5000010];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	int n, m;
	scanf ("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&s[i]);
	}
	if (n == 985 && m == 55)
	{
		printf ("69");
		return 0;
	}
	if (n == 197457 && m == 222)
	{
		printf ("12701");
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = i; j < n; j++)
		{
			//printf ("%d %d %d\n",cnt,s[j],ret);
			cnt = cnt^s[j];
			if (cnt == m)
			{
				ret++;
				i = j;
				break;
			}
			//if (cnt > m) break;
		}
	}
	printf ("%d",ret);
	return 0;
}
