#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, z;
	cin >> n >> m;
	int s[n*m + 5];
	
	cin >> z;
	s[0] = z;
	
	for(int i = 1;i < n*m;i++){
		cin >> s[i];
	}
	sort(s, s+21);
	int j = 20;
	while(j){
		if(s[j] == z){
			if(j % n == 0){
				if(j % 2 == 0){
					cout << j/n - 1 << " " << 0;
					return 0;
				}
				else{
					cout << j/n-1 << " " << n;
					return 0;
				}
			}
			else{
				if(j / n % 2 == 0){
					cout << j/n << " " << j%n;
					return 0;
				}
				else{
					cout <<j/n << " " << n - j%n;
					return 0;
				}
			}
		}
		j--;
	}
	
}

