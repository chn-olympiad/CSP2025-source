#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],b[1000010];
int main()
{
	int i;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0,y=0,lens=s.length();
	for (i=0;i<lens;i++)
	{
		if (s[i]>='0' and s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
		y++;
	}
	int x=y;
	int z=0;
	sort(a+x,a+i+x);
	for (i=0;i<k;i++)
	{
		b[i]=a[i];
		z=z+b[i];
	}
	if (z==0)
	{
		cout<<0;
		return 0;
	}
	sort(b,b+i);
	for (i=k-1;i>=0;i--)
	{
		printf("%d",b[i]);
	}
	return 0;
}
