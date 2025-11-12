#include <iostream>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m;
	srand(n * m);
	cout << rand() % (n * m) << endl;
	return 0;
}