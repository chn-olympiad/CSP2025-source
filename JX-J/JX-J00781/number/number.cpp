#include <bits/stdc++.h>
using namespace std;
string s;
long long i,b[1000005],j=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	while(s[i]!='\0')
	{
		int a;
		a=s[i];
		if(a>=48&&a<=57)
		{
			b[j]=a-48;
			j++;
		}
		i++;
	}
	j--;
	sort(b+1,b+j+1,cmp);
	for(int k=1;k<=j;k++)
	{
		cout << b[k];
	}
	return 0;
}
