#include<bits/stdc++.h>
using namespace std;
int ans,a[1000002],i=0;
char b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf(" %c",&b)!=EOF)
	{
		if(b>='0'&&b<='9')
		{
			i++;
			a[i]=int(b-'0');
		}
	}
	sort(a+1,a+i+1);
	for(int q=i;q>=1;q--)
	{
		printf("%d",a[q]);
	}
	return 0;
}
