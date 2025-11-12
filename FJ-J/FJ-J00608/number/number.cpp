#include<bits/stdc++.h>
using namespace std;
char s[1000000],a[100000];
int js=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[js]=s[i];
			js++;
		}
	}
	for(int i=0;i<=js-1;i++)
		for(int j=0;j<=js-2-i;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	for(int i=0;i<=js-1;i++)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
