#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i <= s.length() - 1; i++)
		for (int k = 0; k <= 9; k++)
			if ((int)s[i] - 48 == k){
				a[k]++;
				break;
			}
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= a[i]; j++)
			cout << i;
	}
	fclose(stdin);
	fclose(stdout);
}
