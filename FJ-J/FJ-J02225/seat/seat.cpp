#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,s,r,a[101];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	s = n * m;
	for (int i = 1;i <= s;i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a+1,a+s+1);
	int i = 0;
	while(a[s - i] != r){
		i++;
	}
	r = i + 1;
	x = r / n + 1;
	y = r % n;
	if (x % 2 == 1 && y != 0){
		cout << x << ' ' << y;
	}else if ((x % 2 == 0 && y == 0) || (x % 2 == 1 && y == 0)){
		cout << (x - 1) << ' ' << n; 
	}else {
		cout << x << ' ' << (n - y + 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
