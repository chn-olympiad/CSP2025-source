#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	vector<int> n;
	string s;
	cin >> s;
	for(int i = 0; s[i]; i++)
		if(isdigit(s[i]))
			n.push_back(s[i] - '0');
	sort(n.begin(), n.end(), greater<int>());
	for(int i : n)
		cout << i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}