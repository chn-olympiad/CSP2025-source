#include <iostream>
#include <fstream>
using namespace std;

int n,k,a[500010];
bool f1 = true;

bool check(int n) {
	int sum = a[1],i=2;
	while(sum != k) {
		sum ^= a[i];
	}
	return 0;
}

int binary_search(int l,int r) {
	return 0;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i] != 1) f1 = false;
	}
	if(f1 && (k==0)) {
		cout<<n/2;
		return 0;
	}
	return 0;
}
