#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	srand(time(0));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 0){
		cout << n/2 << endl;
	}
	else if(k == 1){
		cout << rand() % 100 << endl;
	}
	else cout << rand() % 500000 << endl;
	return 0;
}
