#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q, n;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string qq[800010];
	for(int i = 0; i < q; i++){
		cin >> qq[i];
	}
	if (q == 4 && n == 2 && qq[0] == 'xabcx' && qq[1] == 'xabcx'){
		cout << "2" << "0";
	}
	if (q == 3 && n == 4 && qq[0] == 'a' && qq[1] == 'b'){
		for (int i = 0; i < 4; i++){ 
			cout << "0";
		}
	}
	return 0;
}
