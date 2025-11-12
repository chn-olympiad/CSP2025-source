#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("seat.in","r",stdin);
//	freopen("seat4.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int R;
	cin >> R;
	int rk =1;
	int s;
	for(int i=0;i<n*m-1;i++){
//		cin >> s;
		scanf("%d",&s);
		if(s > R) rk++;
	}
	int x = (rk - 1)/n+1;
//	cout << x << ' ';
	int y= (rk-1)%n+1;
	if(x % 2 == 0) y=n-y+1;
	cout << x << ' ' << y;
	return 0;
}