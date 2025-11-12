#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int num[N];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;
	int cnt = 0;
	//cout << s.size() << endl;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] <= '9' and s[i] >= '0') 
		{
			num[cnt] = s[i] - '0';
			cnt++;
		}
	}
	sort(num, num + cnt);
	for(int i = cnt - 1; i >= 0; i--)
	{
		cout << num[i];
	}
	return 0;
}