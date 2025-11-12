#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.length();i++)if(s[i]>='0'&&s[i]<='9')
	{
		a[++j]=s[i]-48;
	}
	sort(a+1,a+j+1);
	for(int i=j;i;i--)printf("%d",a[i]);
	puts("");
	return 0;
}
