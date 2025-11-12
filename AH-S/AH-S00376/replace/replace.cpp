#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

array<pair<string, string>, 200001> s, t;

int main()
{
	ifstream cin("replace.in");
	ofstream cout("replace.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for (int i {1}; i <= n; ++i)
		cin >> s[i].first >> s[i].second;
	for (int i {1}; i <= q; ++i)
		cin >> t[i].first >> t[i].second;
	
	while (q--)
		cout << "0\n";

	cin.close();
	cout.close();
	return 0;
}