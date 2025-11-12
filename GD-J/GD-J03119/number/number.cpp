#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> arr;
int solve()
{
	cin >> s;
	for (char i : s) if (isdigit(i)) arr.push_back(i - '0');
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i : arr) cout << i;
	return 0;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
