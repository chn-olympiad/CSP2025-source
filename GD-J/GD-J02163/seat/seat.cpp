#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,s = 1,x,y;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout); 
	cin >> n >> m;
	cin >> r;
	for(int i = 2;i <= n * m;i++){
		cin >> c;
		if(c > r){
			s++;
		}
	}x = s / n;
	y = s % n;
	if(x % 2 == 1){
		cout  << x+1 << ' ' << y+1;
	}else{
		cout << x+1 << ' ' << m-y-1;
	}
	return 0;
}
