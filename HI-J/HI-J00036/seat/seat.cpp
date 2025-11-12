#include<bits/stdc++.h>
using namespace std;

int n, m, R, c, r;
int a[101];
int cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++){
		cin >> a[i];
		if (i==1)  R = a[i];
	}
	sort(a+1, a+n*m+1, cmp);
	for(float i=1; i<=n*m; i++){
		if (a[int(i)]==R){
			c = ceil(i/n);
			r = int(i)%n;
			if (c%2==0)  r = n+1-r;
			if (r==0)  r = n;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}

