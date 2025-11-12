#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], k;
int awy(int x, int y){
	int q = 1, xz = 0, xc = 0, yz = 0, yc = 0, ans = 0, ansx = 0;
	while(x > 0){
		xz += q * (x%2); 
		x /= 2;
		q *= 10;
		xc++;
	}
	
	q = 1;
	while(y > 0){
		yz += q * (y%2); 
		y /= 2;
		q *= 10;
		yc++;
	}

	q = 1;
	while(xc>0 && yc>0){
		if (xz%10 != yz%10){
			ans += q;
		}
		q*=10;
		xz /= 10;
		yz /= 10;
		xc--;
		yc--;
	}
	if (xc>0){
		while(xc>0){
			ans += q;
			q*=10;
			xc--;
		}
	}
	else{
		while(yc>0){
			ans += q;
			q*=10;
			yc--;
		}
	}
	
	q = 1;
	while(ans > 0){
		if (ans % 10 == 1){
			ansx += q; 
		}
		q *= 2;
		ans /= 10;
	}
	return ansx;
}
int dfs(long long x){
	int z = 0, ans = 0;
	if (x > n){
		return 0;
	}
	for (int i = x; i <= n; i++){
		z = a[i];
		if (z == k){
			ans = max(ans, dfs(i+1)+1);
		}
		for (int j = i+1; j<= n; j++){
			z = awy(z, a[j]);
			if (z == k){
				ans = max(ans, dfs(j+1)+1);
			} 
		}
	}
	return ans; 
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	if (n > 10){
		int sum = 0;
		if (k == 0){
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0){
					sum++;
				}
				else{
					if (a[i+1] == 1){
						sum++;
					}
					++i;
				} 
			}
		}
		else{
			for (int i = 1; i <= n; i++){
				if (a[i] == 1){
					sum++;
				}
			}
		}
		cout << sum;
		return 0;
	}
	cout << dfs(1);
	return 0;
} 
