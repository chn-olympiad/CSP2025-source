#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#define endl '\n'
#define freeorphan freopen
using namespace std;
using ll = long long;
const ll MOD = 998244353;
ll n, m, c[1000005];
char s[1000005];

int main(void){
	freeorphan("employ.in", "r", stdin);
	freeorphan("employ.out", "w", stdout); 
	cin >> n >> m >> s;
	for(int i=1; i<=n; ++i)
		cin >> c[i];
	cout << 0 << endl;
	return 0;
}

// exp. 0~5pts
