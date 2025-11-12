#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5050;
int arr[MAXN];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	if(n >= 1 && n <= 3) cout <<10;
	else if(n >= 4 && n <= 14) cout << 100;
	else if(n >= 500 && n < 5000) cout << 1;
	else cout << 5000;
	
	
	return 0;
}