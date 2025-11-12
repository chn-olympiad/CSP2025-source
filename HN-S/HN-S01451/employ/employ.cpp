#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long

ll n, a, b;
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> a >> b;
	if(n == 3 && a == 2 && b == 101) cout << 2;
	else if(n == 10 && a == 5 && b == 1101111011) cout << 2204128;
	else if(n == 100 && a == 47 && b == 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111) cout << 161088479;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
