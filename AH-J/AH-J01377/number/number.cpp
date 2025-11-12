#include <bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int c,int b)
{
	return c>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int m=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			a[m]=s[i]-'0';
			m++;
		}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++)
		printf("%d",a[i]);
	return 0;
}
