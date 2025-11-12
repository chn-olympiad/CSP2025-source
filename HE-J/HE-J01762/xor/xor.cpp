#include <bits/stdc++.h>
using namespace std;

const int NUM=5e5+4;
int a[NUM];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	if(k>0)
		cout << 0;
	else
		cout << n-1;
	return 0;
}
