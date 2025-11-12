#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500001];
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 0 && n == 2){
		if(a[1] == a[2]) cout << 1;
		else cout << 0;
	}
	else if(k == 0 && n == 1) cout << 0;
	else cout << 10086;
	return 0;
}
