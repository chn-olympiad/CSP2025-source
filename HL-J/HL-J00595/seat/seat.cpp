#include<bits/stdc++.h>
using namespace std;
int n,m,b,c,l,h;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	b = a[1];
	for(int i = 1;i <= m*n;i++){
		if(a[i] >= b) c+=1;
	}
	h = c % n;
	if(h == 0){
		h = n;
		l = c / n;
	}
	else l = c / n + 1;
	cout << l <<" "<<h;
	return 0;
}
