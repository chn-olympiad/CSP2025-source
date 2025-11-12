// From ZZY 2025.11.1 (~-~)
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in("number.in");
	ofstream out("number.out");
	string s;
	in >> s;
	int cnt[10]{};
	for (auto c : s) {
		if (isdigit(c)) cnt[c - '0']++;
	}
	
	string ans;
	for (int i = 9; i >= 0; i--) {
		while (cnt[i]--) ans += i + '0';
	}

	out << ans << '\n';
	return 0;
}
