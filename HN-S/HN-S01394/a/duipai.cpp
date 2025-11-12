#include <bits/stdc++.h>
using namespace std;
#define ott(i,l,r) for (int i = (l); i <= (r); i ++)
#define tto(i,l,r) for (int i = (r); i >= (l); i --)
const int N = 1e6 + 110;
int n;
int main () {
	system ("g++ data.cpp -o data");
	system ("g++ std.cpp -o std");
	system ("g++ you.cpp -o you");
	int T = 1000;
	while (T --) {
		system ("./data");
		system ("./std");
		system ("./you");
		if (system ("diff std.out you.out")) 
			return puts ("WA"), 0;
	}
	return 0;
}