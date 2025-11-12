#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int b[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int plan = 0;
	int le, i, j; 
	for(le = 2; le <= n - 1; le++){
		for(i = 1; i <= n - le; i++){
			for(j = i + le; j <= n; j++){
				int l = 1;
				int sum = 0;
				for(int k = i; k <= j; k++){
					b[l] = a[k];
					sum += a[k];
					l++;
				}
				sort(b + 1, b + j + 2);
				if(2 * b[j] < sum){
					plan++;
				}				
			} 
		}	
	}
	cout << plan - i + j - le - a[1] + 1;
	return 0;
}