#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool f = true;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(i > 1 && a[i] != a[i-1]) f = false;
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(f){
		cout << n-2;
		return 0;
	}
	cout << 0;
	return 0;
}
