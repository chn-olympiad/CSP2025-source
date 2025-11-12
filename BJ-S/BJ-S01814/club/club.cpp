#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005],b,c;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b >> c;
		}
		sort(a + 1,a + n + 1,cmp);
		int ans = 0;
		for(int i = 1;i <= n / 2;i++){
			ans += a[i];
		}
		cout << ans;
	}
	return 0;
}
