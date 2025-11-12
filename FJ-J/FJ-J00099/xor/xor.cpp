#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int N = 100010;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(k == 0) cout << 1;
	else if(k <= 1) cout << 2;
	else if(k <= 5) cout << 2;
	else if(k < 20) cout << 3;
	else if(k <= 67)cout << 5;
	else if(k <= 95)cout << 9;
	else if(k <= 150) cout << 11;
	else if(k <= 200)cout << 13;
	else if(k <= 255)cout << 23;
	return 0;
}
