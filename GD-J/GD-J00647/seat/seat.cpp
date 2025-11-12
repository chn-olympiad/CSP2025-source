#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int seat = 1,c,r;
	int a[1005]; 
	memset(a,0,sizeof(a));
	int n,m;
	cin >> n >> m;
	cin >> a[1];
	for(int i = 2;i <= n*m;i++){
		cin >> a[i];
		if(a[i]>a[1])seat++;
	}
	if(seat%n==0){
		r=n;
		c = seat/n;
	}
	else{
		c = seat/n+1;
		seat = seat%n;
		if(c%2==1){
			r = seat;
		}
		else{
			r = n+1 - seat;
		}
	}
	cout << c << " " << r;
	return 0;
	
} 
