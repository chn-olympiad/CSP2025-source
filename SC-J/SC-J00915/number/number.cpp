#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[109000];
	char b[109000];
	int k=0,q=0;
	while(1)
	{
		scanf("%c",&a[q]);
		if(a[q]>'9'||a[q]<'0')
			if(a[q]<'a'||a[q]>'z')
				break;
		q++;
	}
	for(int i=0;i<q;++i)
	{
		
		if(a[i]>='0'&&a[i]<='9')
		{
			b[k]=a[i];
			++k;
		}
	}
	sort(b,b+k);
	for(int i=k-1;i>=0;--i)
	{
		printf("%c",b[i]);
	}
	return 0;
}