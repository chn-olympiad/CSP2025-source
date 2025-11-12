#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r,cnt=1;
	cin >> n >> m;
	cin >> r;
	for(int i=1;i<=n*m-1;i++){
		int a;
		cin >> a;
		if(a > r) cnt++;
	}
	cout << (cnt+n-1)/n << ' ';
	if(((cnt+n-1)/n)%2 == 1) cout << (cnt-1) % n + 1;
	else cout << n - (cnt-1) % n;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
