#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], r, c;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int num=a[1], id=1;
	sort(a+1, a+n*m+1, cmp); 
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			id=i;
			break;
		}
	}
	if(id%n==0){//ÁÐ 
		r=id/n;
	}else{
		r=id/n+1;
	}
	if(id%(2*n)==0){//ÐÐ 
		c=2*n;
	}else{
		c=id%(2*n);
	}
	if(c<=n){
		cout << r << " " << c << endl;
	}else{
		cout << r << " " << 2*n-c+1 << endl;
	}
	return 0;
}
