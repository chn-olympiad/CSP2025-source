#include<bits/stdc++.h>
using namespace std;\
int n, m, a[101], ans = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	cin >> a[i];
	for(int i = 2; i <= n*m; i++)
	if(a[i]>a[1])
	ans++;
	for(int i = 1; i <= n*m; i++){
		ans-=n;
		if(ans==0){
			if(i%2==1)
			cout << i << " " << n;
			else
			cout << i << " 1";
			return 0;
		}
		if(ans<=n){
			if(i%2==0)
			cout << i+1 << " " << ans;
			else
			cout << i+1 << " " << n-ans+1;
			return 0;
		}
	}
	return 0;
}