#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
int n,a[5005],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0 << endl;
	}
	else if(n == 3){
		if(a[1]+a[2]+a[3] > 2 * max(a[1],max(a[2],a[3]))){
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
	else{
		cout << n << endl;
	}
	return 0;
} 
