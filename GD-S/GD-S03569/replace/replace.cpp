#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
#ifdef LOCAL
	bool isin,isout;
	cin >> isin >> isout;
	if (isin)
#endif
	freopen("replace.in","r",stdin);
#ifdef LOCAL
	if (isout)
#endif
	freopen("replace.out","w",stdout);
	
	srand(time(0));
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++)	cout << rand() << '\n';
	return 0;
}

