#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*1e3+5;
int n;
int q[MAXN], sum[MAXN];
int ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> q[i];
	}
	sort(q+1, q+n+1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1]+q[i];
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	for(int i = 3; i <= n; i++){
		for(int j = i-1; j >= 0; j--){
			for(int k = j-2; k >= 0; k--){
				if(i == j){
					if(sum[j]-sum[k] > 2*q[i]) ans++;
					continue;
				}
				if(sum[j]-sum[k]+q[i] > 2*q[i]) ans++;
			}
		}
	}
	cout << ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
