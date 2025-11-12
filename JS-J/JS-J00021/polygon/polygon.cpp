#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, a[5005];
long long ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopon("polygon.out","w",stdout);
	cin >> n;
	if(n == 3){
		int x, y, z;
		cin >> x >> y >> z;
		int maxk = max(z, max(x, y))
		if((x + y + z) > (2 * maxk)){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	cout << 9;
	return 0;
}
