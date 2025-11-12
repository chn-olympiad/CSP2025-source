#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
	}
int h, l, p;
int a[105], a1[105][105];
int sum = 0, w = 1;
int main(){
freopen("seat.in", "r", stdin);
freopen("seat.out", "w", stdout);
cin >> h >> l;
for(int i = 1; i <= h * l; i++){
	cin >> a[i];
}
p = a[1];
sort(a + 1, a + h * l + 1, cmp);
while(sum <= h * l){
	for(int i = 1; i <= h; i++){	
		sum++;
		//cout << "xia";
		a1[i][w] = a[sum];
		//cout << a[sum] << " ";
		if(a[sum] == p){
			cout << w << " " << i;
			return 0;
		}
	}
	for(int i = 1; i < 2; i++){	
		sum++;
		//cout << "you";
		a1[h][i + w] = a[sum];
		//cout << a[sum] << " ";
		if(a[sum] == p){
			cout << i + w << " " << h;
			return 0;
		}
	
	}
	for(int i = h; i > 1; i--){	
		sum++;
		a1[i - 1][1 + w] = a[sum];
		//cout << "shang";
		//cout << a[sum] << " ";
		if(a[sum] == p){
			cout << 1 + w << " " << i - 1;
			return 0;
		}
	}
	w += 2;
}
return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92
