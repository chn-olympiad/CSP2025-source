#include <bits/stdc++.h>
using namespace std;
bool px(int a, int b){
		return a>b;
	}
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	int n,m,marks,num,x,y,a[10002];
	cin >> n >> m;
	for (int i = 0;i< n*m;i++){
		cin >> marks;
		a[i] = marks;
	}
	int xr = a[0];
	sort(a,a+n*m,px);

	for (int j = 0;j< n*m;j++){
		if (xr==a[j])num = j+1;
	}
	
	x = num % n;
	y = num/n;
	if (x == 0){
		if (y%2==0) cout << y << " " << 1;
		else cout << y << " " << n;
	}
	else{
		if (y%2==0)cout << y+1 << " " << x;
		else cout << y+1 << " " << n-x+1;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
