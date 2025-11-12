#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	int n, m;
	cin>>n>>m;
	int a[10010] = {}, l = 1;
	cin>>a[1];
	for(int i = 2;i <= n * m;i++){
		cin>>a[i];
		if(a[i] > a[1]){
			l++;
		}
	}
	int r = 1,c = 1;

	for(int i = 1;i <= l;i++){
		
		if(r == n + 1 || r == 0 && c % 2 == 0){
			c++;
		}
		if(c % 2 == 0){
			r -= 1;
		}
		if(c % 2 == 1){
			r += 1;
		}
		
	}
	if(r == n + 1){
		c++;r = n;
	}else if(r == 0 && c % 2 == 0){
		c++;r = 1;
	}
	
	cout<<c<<' '<<r; 
	cout<<'\n';
	return 0;
} 