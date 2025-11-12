#include<bits/stdc++.h>
using namespace std;

int a[105];
int n,m,score;
int c=1,r=1; // c列 r行 
int dir; // 0向下 1向左 2向上 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin >> n >> m;
	cin >> score;
	a[1] = score; 
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
	} 
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i] == score) break;
		if(dir == 0){ // 向下 
			r++;
			if(r == n) dir = 1;
		}else if(dir == 1){ // 向左 
			c++;
			if(r == 1) dir = 0;
			else if (r == n) dir = 2;
		}else if(dir == 2){ // 向上 
			r--;
			if(r == 1) dir = 1;
		}
	}
	cout << c << " " << r; 
	
	return 0;
} 
