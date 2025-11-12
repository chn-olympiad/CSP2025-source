#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],ans;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n-2; i++){
		if(a[i] + a[i+1] + a[i+2] > 2 * a[i] && a[i] + a[i+1] + a[i+2] > 2 * a[i+1] && a[i] + a[i+1] + a[i+2] > 2 * a[i+2]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
