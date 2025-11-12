#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int m;
int b[15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			b[m]=s[i]-'0';
			m++;
		}
	}
	sort(b,b+m,cmp);
	for(int i=1;i<=m;i++)
	{
		cout << b[i];
	}
	return 0;
}