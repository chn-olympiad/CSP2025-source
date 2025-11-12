#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int js=0;
	for(int i = 0 ; i < s.size(); i++)
	{
		if(s[i]>='0'&&s[i]<= '9')
		{
			a[js]=s[i]-'0';
			js++;
		}
	}
	sort(a,a+js);
	for(int i = js-1 ; i >= 0 ; i--)
	{
		cout << a[i];
	}
	return 0;
}
