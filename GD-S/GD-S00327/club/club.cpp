#include <iostream>
#include <cstdio>
using namespace std;
int t , n;
int a[100005][5];
int d[4][100005];
int x = 0;

int max(int a , int b , int c){
	x = 0;
	if(a > b){
		b = a;
	}else{
		x = 1;
	}
	if(b > c){
		c = b;
	} else {
		x = 2;
	}
	return c;
}

int div(int a , int b , int c){
	if(b - a < c- a){
		return b - a;
	}
	return c - a;
}

int main(){
	freopen("club.in" , "r" , stdin);
	//freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--){
		int sum = 0;
		int num[4] = {0};
		int sort[20004] = {0};
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			
			sum += max(a[i][0] , a[i][1] , a[i][1]);
			
			d[x][num[x]++] = i;
		}
		max(num[0] , num[1] , num[2]);
		int e = x;
		for(int i = 0 ; i < num[e] ; i++){
			sort[div(a[d[e][i]][e] , a[d[e][i]][(e + 1) % 3] , a[d[e][i]][(e + 2) % 3])]++;
		}
		
		int flag = num[e] - n / 2;
		for(int i = 0 ; i <= 20000 ; i++){
			if(flag <= 0){
				break;
			}
			if(sort[i]){
				sum -= i;
				sort[i--]--;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
