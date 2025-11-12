#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	int sum = 1,ans = 0;
	for(int i = 2;i < n;i++){
		ans+= sum;
		sum++;
	}
	cout << ans;
	return 0;
}
