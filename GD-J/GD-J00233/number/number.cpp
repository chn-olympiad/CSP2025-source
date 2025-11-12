#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1e6+10;
string s;
int a[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),pos=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[pos]=s[i]-'0';
			pos++;
		}
	}
	sort(a+1,a+pos+1,cmp);
	for(int i=1;i<pos;i++)
	cout<<a[i];
	return 0;
}
