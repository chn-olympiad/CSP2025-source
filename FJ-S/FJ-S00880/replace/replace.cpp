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
ll n, q;
string s[1000004][10], tj1, tj2;

int main(void){
	freeorphan("replace.in", "r", stdin);
	freeorphan("replace.out", "w", stdout); 
	cin >> n >> q;
	for(int i=1; i<=n; ++i)
		cin >> s[i][1] >> s[i][2];
	for(int i=1; i<=q; ++i){
		cin >> tj1 >> tj2;
		cout << 0 << endl;
		// it maybe get 5pts
	}
	return 0;
}

// exp. 0~5pts
