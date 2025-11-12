#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	map<char,int> mp;
	mp['0'] = 0;
	mp['1'] = 1;
	mp['2'] = 2;
	mp['3'] = 3;
	mp['4'] = 4;
	mp['5'] = 5;
	mp['6'] = 6;
	mp['7'] = 7;
	mp['8'] = 8;
	mp['9'] = 9;
	string s;
	cin >> s;
	int n = 0;
	int a[100000];
	for (int i = 0;i <= s.size()-1;i ++)
	{
		if (s[i] < 'A')
		{
			a[i] = mp[s[i]];
			n++;
		}
	}
	if (s[0] >= 'A')
	{
		a[0] = 0;
		a[1] = 0;
	}
	cout << endl;
	for (int i = 0;i <= s.size()-1;i ++)
	{
		a[i] *= -1;
	}
	sort(a,a+s.size());
	for (int i = 0;i <= s.size()-1;i ++)
	{
		a[i] *= -1;
	}
	long long m = 0;
	for (int i = 0;i <= n-1;i ++)
	{
		m += a[i] * pow(10,n-i-1);
	}
	cout << m;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
 
