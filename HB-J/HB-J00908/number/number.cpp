#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int s[1000100];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	int len=x.length();
	int tot=0;
	for (int i=0;i<len;i++)
	{
		if (x[i]>='0' && x[i]<='9')
			s[tot++]=int(x[i]-'0');
	}
	sort(s,s+tot,cmp);
	for (int i=0;i<tot;i++)
		cout<<s[i];
	cout<<'\n';
	return 0;
}
