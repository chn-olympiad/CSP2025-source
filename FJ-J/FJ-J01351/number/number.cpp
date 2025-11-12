#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=0;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i <= s.size()-1;i++)
	{
		if(s[i] == '1'||s[i] == '2'||s[i] == '3'||s[i] == '4'||s[i] == '5'||s[i] == '6'||s[i] == '7'||s[i] == '8'||s[i] == '9'||s[i] == '0')
		{
			a[++cnt] = s[i]-48;
		 } 
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
