#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen(seat.in, "r", stdin);
	freopen(seat.out, "w", stdout);
	
	int m, n, a1, num=1;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin >> x;
		if(i==1)a1=x;
		else if(x>a1)num++;
	}
	int h, l;
	l=(num-1)/n+1;
	h=num-((l-1)*n);
	if(l%2==0)h=n-h+1;
	cout << l << ' ' << h;
	
	return 0;
}
