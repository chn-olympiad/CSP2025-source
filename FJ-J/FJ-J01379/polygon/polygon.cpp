#include<bits/stdc++.h>
using namespace std;
int a[5005];
int sum = 0;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(n < 3){
		cout << "0";
		return 0;
	}
	if(n == 3){
		int ans = 0;
		int maxn = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] > maxn){
				maxn = a[i];
			}
			ans += a[i];
		}
		if(2 * maxn > ans){
			cout << "1";
			return 0;
		}else{
			cout << "0";
			return 0;
		}
	}
	return 0;
}
