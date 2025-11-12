#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,a[105]={0},x=1,b[15][15]={0},c=1;
	cin >> n >> m;
    for(int i=1;i<=m*n;i++) {
    	cin >> a[i];
	}
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int y=1;y<=n;y++) {
			    b[i][y]=c;
			    c++;
	    	}
		}
		else {
			for(int y=n;y>0;y--) {
				b[i][y]=c;
				c++;
			}
		}
	
	}
    for(int i=2;i<=m*n;i++) {
    	if(a[1]<a[i]) {
    		x++;
		}
	}
	if(x==m*n) {
		cout << n << " " << m;
		return 0;
	}
	else if(x==1) {
		cout << "1" << " " << "1";
		return 0;
	}
	 else {
	 	for(int i=1;i<=m;i++) {
	    	for(int y=1;y<=n;y++) {
		        if(b[i][y]==x) {
		        	cout << i << " " << y;
				}
	        }
    	}
    }
	return 0;
} 
