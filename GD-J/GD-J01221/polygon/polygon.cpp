#include<bits/stdc++.h>
using namespace std;
int polygon[5005];
int main() {
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n , sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> polygon[i];
	for(int i = 1; i <= n - 2; i++){
		int maxn = max(polygon[i],max(polygon[i + 1],polygon[i + 2]));
		int ans = polygon[i] + polygon[i + 1] + polygon[i + 2];
		if(ans > 2 * maxn) sum++;
		for(int j = i + 2; j <= n; j++){
			maxn = max(maxn,polygon[j]);
			ans = ans + polygon[j];
			if(ans > 2 * maxn) sum++;
		}
	}
	cout << sum;
} 
