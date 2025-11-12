#include <bits/stdc++.h>
using namespace std;
int n, sum, a[5000];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int maxn = INT_MIN, maxw;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1, cmp);
	if(a[1] * 2 < a[2] + a[3]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
} 
