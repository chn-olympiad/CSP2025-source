#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	int a[s.size()+1] = {0};
	int cnt = 0;
	for(int i = 0;i<=s.size();i++)
	{
		if(s[i]>='0' && s[i] <='9')
		{
			a[++cnt] = s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i = cnt;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
 } 

