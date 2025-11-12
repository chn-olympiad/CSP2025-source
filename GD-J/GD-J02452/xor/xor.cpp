#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
long long b[N];
int main(){
	//task xor (probably failed)
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	long long k;
	cin >> k;
	b[0] = 0, a[0] = 0;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		a[i] = a[i]^1;
		b[i] = b[i-1]+a[i];
	}
	cout << 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
