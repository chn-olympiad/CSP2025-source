#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x = n * m;
	for(int i = 1; i <= x; i++) cin >> a[i];
		int y = a[1];
	sort(a+1,a+1+n);
	for(int i = 1; i <= x; i++){
		if(a[i] == y) {
			if(i % n == 0){
				cout << i / n + 1 << i % n + 1;
			}else{
				cout << i / n + 1 << n - i % n + 1;
			}
		}
	}
	return 0;
}
