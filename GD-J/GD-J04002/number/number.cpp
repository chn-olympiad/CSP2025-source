#include<iostream>
#include<algorithm>
#include<cmath>
#include<string> 
using namespace std;
string s;
int len,a[1000005],len2;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	for(int i = 0;i < len;i++)
	{
		if(s[i] <= '9' && s[i] >= '1')
		{
			len2++;
			a[len2] = s[i] - '0';
		}
		else if(s[i] == '0')
		{
			len2++;
			a[len2] = 0;
		}
	}
	sort(a + 1,a + len2 + 1,cmp);
	for(int i = 1;i <= len2;i++)
	{
		cout << a[i];
	}
	return 0;
}

