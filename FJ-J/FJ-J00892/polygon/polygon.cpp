#include <bits/stdc++.h>
using namespace std;
int n, a[5001],num = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n-2;i++){
		for(int j = i+1;j <= n-1;j++){
			for(int k = j+1;k<=n;k++){
				num++;
			}
		}
	}
	cout << num;
	return 0;
}
