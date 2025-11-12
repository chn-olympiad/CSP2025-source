#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	int flag = 0;
	cin >> n >> k;
	int ans = 0;
	int a[500000] = {0};
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(k == 0){
		for(int i = 0;i < n;i++){
			if(a[i] % 2 == 0){
				ans++;
			}
		}
	}
	if(k == 1){
		for(int i = 0;i < n;i++){
			if(a[i] == 1){
				ans++;
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

