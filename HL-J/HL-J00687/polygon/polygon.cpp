#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int ans;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int sum = 0,maxl = 0;
		sum += a[i]; 
		if(a[i] > maxl){
			maxl = a[i];
		}
		if(sum > maxl * 2){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

