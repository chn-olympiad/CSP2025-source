#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN], s[MAXN];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, c = 1, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			c = 0;
		}
	}
	if(n < 3){
		cout << "0";
		return 0;
	}
	if(c == 1){
		int sum1 = 0;
		for(int i = 1; i <= n-2; i++){
			sum1 += i*(n-i-1);
		}
		cout << sum1;
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		s[i] = a[i] + s[i-1] ;
	} 
	for(int i = 3; i <= n; i++){
		if(s[i-1] <= a[i]){
			continue;
		}else{
			sum++;
			if(i == 3) continue;
			for(int j = 1; j < i; j++){
				if(s[i-1] - s[j] > a[i]) sum++;
				else{
					for(int k = 1; k <= j; k++){
						if(s[i-1]-s[j]+a[k]>a[j]) sum++;
					}
				}
			}
		}
	} 
	cout << sum;
	return 0;
} 