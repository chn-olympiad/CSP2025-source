#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {return a > b;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector <int> a;
	for (int i = 0;i < s.size();i ++)
	{
		if (s[i] <= '9' && s[i] >= '0')
		{
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for (int i = 0;i < a.size();i ++)
    {
        cout << char(a[i]);
    }
	return 0;
}
