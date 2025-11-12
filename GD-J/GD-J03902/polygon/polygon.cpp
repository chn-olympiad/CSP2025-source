#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
#ifdef LOCAL
	bool isin,isout;
	cin >> isin >> isout;
	if (isin)
#endif
	freopen("polygon.in","r",stdin);
#ifdef LOCAL
	if (isout)
#endif
	freopen("polygon.out","w",stdout);
	
	srand(time(0));
	cout << rand();
	return 0;
}

