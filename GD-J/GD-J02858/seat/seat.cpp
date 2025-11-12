#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,b;
	cin >> n >> m >> b;
	int a[105];
	a[1] = b;
	for(int i = 2;i <= n*m;i++){
		cin >> a[i];
	}
	if(n == 1 && m == 1){
		cout << "1 1";
		return 0;
	}
	int j = n*m;
	while(j){
		for(int i = 1;i <= n*m;i++){
			if(a[i] < a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
		j--;	
	}
	
	if(n == 1){
		for(int i = 1;i <= n*m;i++){
			if(a[i] == b){
				cout << i << " 1";
			}
		}
	}
	if(m == 1){
		for(int i = 1;i <= n*m;i++){
			if(a[i] == b){
				cout << "1 " << i;
			}
		}
	}
	if(n == 2 && m == 2){
		for(int i = 1;i <= n*m;i++){
			if(a[i] == b){
				if(i == 1 || i == 2){
					cout << "1 " << i;
				}
				else if(i == 3){
					cout << "2 2";
				}
				else{
					cout << "2 1";
				}
			}
		}
		return 0;
	}
	if(n == 2){
		for(int i = 1;i <= n*m;i++){
			if(a[i] == b){
				int c = ceil(i / 2);
				int d = i % 2;
				if (d == 1){
					c++;
				}
				if (d == 0){
					d = 2;
				}
				cout << c << " " << d;
			}
		}
		return 0;
	}
	return 0;
}

