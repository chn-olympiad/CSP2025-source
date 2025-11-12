#include<bits/stdc++.h>
using namespace std;
int n,m,r,ans = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	for(int i = 2,x;i <= n*m;i++){
		cin >> x;
		if(x > r) ans++;
	}
	int le = (ans-1) / n + 1,hang;
	if(le & 1) hang = ans - (le-1)*n;
	else hang = n - (ans - (le-1)*n) + 1;
	cout << le << " " << hang << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
