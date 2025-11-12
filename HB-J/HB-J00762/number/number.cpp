#include <iostream>
#include <algorithm>
using namespace std;
int a[100005]={},cnt=0,len;
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len=s.size();
	for (int i=0;i<len;i++)
	{
		if ('0'<=s[i] && s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for (int i=0;i<cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
