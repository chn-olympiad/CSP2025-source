#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s = n * m;
	int a[s + 5];
	for(int i = 1;i <= s;i++){
		cin >> a[i];
	}
	sort(a + 2,a + s + 1);
	int x = 1,y = 1;
	bool z = 1;
	for(int i = s;i >= 2;i--){
		if(a[1] > a[i]){
			cout << x << " " << y;
			return 0;
		}
		if(z){
			if(y == n){
				z = 0;
				x++;
			}else{
				y++;
			}
		}else{
			if(y == 1){
				z = 1;
				x++;
			}else{
				y--;
			}
		}
	}
	cout << m << " " << n;
}
