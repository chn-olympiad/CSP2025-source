#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int seatnum[105], rseat;
bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n*m; i++){
		cin >> seatnum[i];
	}
	rseat = seatnum[0];
	sort(seatnum, seatnum+n*m, cmp);
	for(int i=1; i<=n*m; i++){
		if(seatnum[i-1] == rseat){
			cout << ceil(i*1.0/n);
			if(i%n==0){
				if(i/n%2==0){
					cout << " " << 1;
				}
				else{
					cout << " " << n;
				}
				break;
			}
			else{
				if(i/n%2){
					cout << " " << n+1-i%n;
				}
				else{
					cout << " " << i%n;
				}
				break;	
			}
		}
	}
	return 0;
}
