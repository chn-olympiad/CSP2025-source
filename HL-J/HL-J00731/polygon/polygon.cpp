#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n = 0;
	int a[5] = {0};
	int ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			for(int k = j+1;k < n;k++){
				if((a[i] + a[j] + a[k]) > max(max(a[j],a[i]),a[k])*2){
					ans++;
				}
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

