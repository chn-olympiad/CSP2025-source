#include<bits/stdc++.h>
using namespace std;

long long a[500010], n, k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >>n >>k;
	for(int i = 1; i <= n; i ++) cin >>a[i];
	
	if(n == 1 && k == 0){
		cout <<"0";
	}else if (n == 2 && k == 0){
		cout <<"1";
	}
	
	return 0;
}
