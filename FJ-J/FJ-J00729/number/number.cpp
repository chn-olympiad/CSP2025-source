#include <bits/stdc++.h>
using namespace std;

const unsigned int N = 1e6 + 5;

string s = "";
vector<int> a;

bool isDigit(char c) {
	return (9 >= int(c - '0') && int(c - '0') >= 0) ? true : false;
}

// dfs memory
unsigned long long maxn = 0;
unsigned long long number = 0;

void dfs(vector<bool>& visited) {
	for (int i = 0; i < a.size(); i++) {
		if (!visited[i]) {
			number = number * 10 + a[i];
			maxn = max(number, maxn);
			visited[i] = true;
			dfs(visited);
			visited[i] = false;
			number /= 10;
		}
	}
	return;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);	
	
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (isDigit(s[i])) {
			a.push_back(int(s[i]) - '0');
		}	
	}
	
	vector<bool> visited(a.size(), false);	
	dfs(visited);

	cout << maxn;

	fclose(stdin);
	fclose(stdout);

	return 0;
}

