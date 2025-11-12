#include<bits/stdc++.h>
using namespace std;
int n,m,a[103],b,x,h,l;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	b = a[1];
	for(int i = 2; i <= n * m; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == b){
			x = i;
			break;
		}
	}
	if(x % n == 0) l = x/n;
	else l = x/n+1;
	if(l % 2 == 1){
		if(x % n == 0) h = n;
		else h = x % n;
	}
	else {
		if(x % n == 0) h = 1;
		h = n-x%n+1;
	}
	cout << l  << ' ' << h;
	return 0;
}
