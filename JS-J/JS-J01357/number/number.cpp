#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n =s.size(),j = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			a[j] = s[i]-'0';
		}	
	}
	sort(a+1,a+j+1);
	for(int i = j; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
