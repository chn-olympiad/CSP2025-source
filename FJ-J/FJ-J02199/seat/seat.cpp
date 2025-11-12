#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int score = a[1];
	int cnt = 1;
	for(int i = 2; i <= n * m; i++){
		if(a[i] > score){
			cnt++;
		}
	}
	int c = (cnt - 1) / n + 1;
	int r = cnt % n;
	if(r == 0){
		r = n;
	}
	if(c % 2 == 0){
		r = n - r + 1; 
	}
	cout << c << " " << r << endl;
	return 0;
}

