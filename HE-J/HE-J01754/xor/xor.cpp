#include <bits/stdc++.h>

using namespace std;

int a[500005]; 

int main ()
{
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int q=1; q<=n; q++) cin >> a[q];
	
	int cnt = 0;
	if (n<=2){
		cout << 1;
		return 0;
	}
	if (n<=10){
		int sum=0;
		for (int i=1; i<=n; i++){
			for (int j=i; j<=n; j++){
				if ( !(sum & a[j]) == k){
					sum = sum & a[j];
					i = j+1;
					cnt ++;
					break;
				}
			}
		}
	}
	cout << cnt; 
	return 0;
}
