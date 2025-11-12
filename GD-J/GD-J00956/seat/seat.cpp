#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,x=0,y=0,q,w;
	cin >> n >> m;
	int a[n*m + 15];
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	c = a[1];
	for(int i = 2;i <= n*m;i++){
		if(a[i] > c)x++;
	}
	q = x/n + 1;
	if(q%2 == 1){
	    w = (x+1)%m;
	    if(w == 0)w = m;
	}else{
		w = m - x%m;
	}
	cout << q << " " << w;
	return 0;
}
