#include <iostream>
#include <string> 
#include <cstdio>
#include <array>

std::array <int, 10> b;
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out","w", stdout);
	
	std::string s;
	std::cin >> s;
	for (unsigned int i=0; i<s.size(); i++) {
		if (s[i]>='0' && s[i]<='9')
			b[s[i]-'0'] ++;
	}
	
	for (int i=9; i>=0; i--) {
		for (int j=0; j<b[i]; j++)
			std::cout << i;
	}
	std::cout << std::endl;
}
