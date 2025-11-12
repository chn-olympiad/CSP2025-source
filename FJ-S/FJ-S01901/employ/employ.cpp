#include<bits/stdc++.h>
using namespace std;
long long  n , m  , ooo[505];
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	ooo[1] = 1;
	ooo[n] = n;
	for(int i = n ; i < m ; i++){
		ooo[i] = ooo[i+1] * i;
	}
	cout << ooo[m + 1] % 998244353;
	return 0;
}
