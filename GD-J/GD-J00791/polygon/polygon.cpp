#include <bits/stdc++.h>
using namespace std;

int a[5010],sum1,sum2;

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] == 1) sum1++;
		sum2++;
	}
	if(sum1 == sum2){
		cout << n - 3 + 1;
	}
	return 0;
}
