#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x = m*n;
	int a[x];
	for(int i = 0; i < x; i++){
		cin >> a[i];
	}
	int r = a[0];
	int cnt = 0;
	while(cnt != x -1){
		cnt = 0;
		for(int i = 0; i < x - 1; i++){
			if(a[i] < a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
		for(int i = 0; i < x-1; i++){
			if(a[i] >= a[i+1]){
				cnt++;
			}
			//cout <<"cnt:"<< cnt << " ";
		}
	}
	int b;
	for(int i = 0; i < x; i++){
		if(a[i] == r){
			b = i + 1;
		}
	}
	//cout << b << " ";
	int hang;
	int lie;
	if(b == n){
		lie = b/n;
	}else{
		lie = b/n+1;
	}
	if(lie % 2 == 0){
		if(b % n == 1){
			hang = 1;
		}else{
			hang = n - b % n + 1;
		}
	}else {
		if(b %n == 0){
			hang = n;
		}else{
			hang = b % n;
		}
	}
	cout << lie <<" "<< hang ;
}
