#include<bits/stdc++.h>
using namespace std;
int n, m, g, w;
int c, r;
int a[110];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int cnt = n*m;
	for(int i = 1; i <= cnt; i++) cin >> a[i];
	g = a[1];
	sort(a+1, a+cnt+1, cmp);
	
	for(int i = 1; i <= cnt; i++){
		if(a[i]==g){
			w = i;
			break;
		}
	}
	
	c = w/n;
	w %= n;
	if(w!=0){
		c++;
		if(c%2==0) r = n-w+1;
		else r = w;
	}
	else{
		if(c%2==0) r = 1;
		else r = n;
	}
	
	cout << c << ' ' << r;
	return 0;
	
	
	
}
