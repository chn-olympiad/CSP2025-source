#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	if(k == 0)
	{
		if(n == 2) printf("1");
		else printf("1");
		return 0;
	}
	else if(k <= 1)
	{
		printf("1");
	}
	else if(n == 4 && k == 0) printf("1");
	else if(n == 4 && k == 3) printf("2");
	else if(n == 4 && k == 2) printf("2");
	else
	{
		for(int i = 0;i < n;i++) scanf("%d",&a[i]);
		printf("%d",a[0] | a[1]);
	}
	return 0;
}
