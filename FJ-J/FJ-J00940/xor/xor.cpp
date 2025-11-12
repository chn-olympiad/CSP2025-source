#include <bits/stdc++.h>
using namespace std;
int a[500001],c;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(a[i]==k)
			c++;
	}
	cout << c;
	return 0;
}
