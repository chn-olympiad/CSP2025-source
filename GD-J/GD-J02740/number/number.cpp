#include<bits/stdc++.h>
using namespace std;
string s;
long long ans[12];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			ans[s[i] - '0']++;	
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = ans[i] ; j > 0; j--)
		{
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
