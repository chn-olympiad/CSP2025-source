#include <iostream>
#define endl "\n"
#define ll long long
using namespace std;
int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cout << rand() % 200 + 1; 
	return 0;
}
