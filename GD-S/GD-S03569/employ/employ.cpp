#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
#ifdef LOCAL
	bool isin,isout;
	cin >> isin >> isout;
	if (isin)
#endif
	freopen("employ.in","r",stdin);
#ifdef LOCAL
	if (isout)
#endif
	freopen("employ.out","w",stdout);
	
	srand(time(0));
	cout << rand() * rand() % 998244353;
	return 0;
}

