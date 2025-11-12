#include<bits/stdc++.h>

std::vector<int> v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c;
	while((c = getchar()) != '\n' && c != ' ' && c != '\0') {
		if(isdigit(c))
			v.push_back(c - '0');
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	for(int i : v)
		printf("%d", i);
	return 0;
}

