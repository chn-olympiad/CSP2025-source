#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	long long m[6000] = {0};
	long long k;
	cin >> n;
	long long maxv = -2e9,sum = 0;
	
	for (int i = 1;i <= n;i++){
		cin >> m[i];
		maxv = max(maxv,m[i]);
		sum += m[i];
	}
	if (n <= 3){
		if(sum > 2*maxv) cout << 1;
		else cout << 0;
		return 0;
	}
	return 0;
}
