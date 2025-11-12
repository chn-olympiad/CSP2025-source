#include<bits/stdc++.h>
using namespace std;
char s;
char a[1000010];
int i=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s=='9' || s=='8' || s=='7' || s=='6' || s=='5' || s=='4' || s=='3' || s=='2' || s=='1' || s=='0')
		{
			a[i]=s;
			i++;
		}
	}
	i=0;
	while(a[i])
	{
		while(a[i])
		{
			if(a[i]<a[i+1])
			{
				char g=a[i];
				a[i]=a[i+1];
				a[i+1]=g;
			}
			i++;
			if(a[i]=='0')
			{
				i=0;
				break;
			}
		}
	}
	while(a[i])
		cout << a[i];
	return 0;
}
