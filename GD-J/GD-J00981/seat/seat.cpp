#include<bits/stdc++.h> 
using namespace std;
int n, m, a[105], b, c, ans1, ans2;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	b = a[1];
	sort(a+1, a+(n*m)+1);
	for(c = 1; c <= n*m; c++){
		if(a[c] == b)break;
	}
	c = n*m-c+1;
	if(c%n==0){
		ans1=c/n;
		ans2=n;
	}else{
		ans1=c/n+1;
		if((c/n)%2==0)ans2=c%n;
		else ans2=n-c%n+1;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
