#include<bits/stdc++.h>
using namespace std;

long long i,a[600000],n;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << 10;
	return 0;
}