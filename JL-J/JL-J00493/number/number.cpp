#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
long long t=0;
char n;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	while(cin>>n)
	{
		if(n>='0'&&n<='9')
		{
			a[t]=n-48;
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
		printf("%lld",a[i]);
	printf("\n");

	return 0;
}

