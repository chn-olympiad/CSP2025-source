#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen('seat.in','r',stdin); 
	freopen('seat.out','w',stdout);
	int n,m,a[105],c,d;
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	int b = a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if (a[i] < a[j]){
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(b == a[i]){
			b = i;
		}
	}
	if((b+1) % n == 0)c = (b+1)/n;
	else c = (b+1)/n+1;
	if(c % 2 == 0)d = n - (b+1) % n;
	else d = (b+1) % n;
	if (d == 0)d = n;
	cout << c << ' ' << d;
	return 0;
}
