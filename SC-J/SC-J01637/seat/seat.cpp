#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105];

bool cmp(int a,int b){
	return a > b;
}

int get_(int x){
	for (int i = 1;i<=n*m;i++){
		if (a[i] == x) return i;
	}
	return -1;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i<=n*m;i++) cin >> a[i];
	int score = a[1];
	sort(a+1,a+n*m+1,cmp);
	int num = get_(score);
	
	int y = (!(num % n) ? num/n : num/n+1),x;
	if (y%2 == 1) x = (!(num%n) ? n : num%n);
	else x = (!(num%n) ? 1 : (n - num%n + 1));
	
	cout << y << " " << x;
}