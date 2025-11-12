#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005];
	int b[1000005];
	cin>>a;
	int al=strlen(a);
	int xb=0,sum=0;
	for(int i=0;i<al;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[xb]=a[i]-'0';
			sum++;
			xb++;
		}
	}
	sort(b,b+sum);
	for(int i=sum-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
