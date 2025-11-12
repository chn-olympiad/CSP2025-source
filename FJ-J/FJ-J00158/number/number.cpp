#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2;

int main()
{
	ios::sync_with_stdio(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s1;
	s1 = " " + s1;
	
	int n = s1.size();
	for (int i = 1; i <= n; ++ i )
		if ('0' <= s1[i] && s1[i] <= '9')
			s2.push_back(s1[i]);
	
	sort(s2.begin(), s2.end(), greater <char>());
	
	cout << s2;
	return 0;
}
