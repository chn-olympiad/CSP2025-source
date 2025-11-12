#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n,m;
int seat[15][15];
int a[105];

bool cmp(int a,int b){
	return a > b; 
}

int x,y,r,z,flag;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	
//	for(int i = 1;i <= m * n;i++){
//		y = (i - 1) / n + 1;
//		z = (y - 1) * n;
//		if(y % 2 == 1){
//			x = i - z;
//		}
//		else x = n + z - i;
//		seat[x][y] = a[i];
//	}
	int cs = 1;
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				seat[j][i] = a[cs]; 
				++cs;
			}
		} 
		if(i % 2 == 0){
			for(int j = n;j >= 1;j--){
				seat[j][i] = a[cs];
				++cs;
			}
		}
		
	}
	
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cout << seat[i][j] << " ";
//		}
//		cout << endl;
//	} 
	
	
	
	for(int i = 1;i <= n;i++){
		flag = 0;
		for(int j = 1;j <= m;j++){
			if(seat[i][j] == r){
				cout << j << " " << i;
				flag = 1;
				break;
			}
		}
		if(flag) break;
 	}
	
	
	
	return 0;
} 
