#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int K = 998244353;
int n,m;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	srand(n * m);
	cout << rand() % K << endl;
	return 0;
}