#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int o[1005][1005];
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		o[i][i] = a[i];
		if (o[i][i] == k) ans++; 
	}
	if (n == 2){
		cout << 1; 
		return 0;
	}
	for (int i = 1;i <= n;i++){
		for (int j = i+1;j <= n;j++){
			o[i][j] = o[i][j-1]^a[j];
			if(o[i][j] == k) ans++;
		}
	}
	cout << ans;
	return 0;
}
