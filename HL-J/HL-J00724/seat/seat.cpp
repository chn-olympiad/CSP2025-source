#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int c[m*n];
	for(int i=0; i<m*n; i++) {
		int a;
		cin>>a;
		c[i]=a;
	}
	int r=c[0];
	for(int i=0; i<m*n+1; i++) {
		for(int j=0; j<m*n-1; j++) {
			if(c[j]<c[j+1]) {
				int d=c[j+1];
				c[j+1]=c[j];
				c[j]=d;
			}
		}
	}
	int w=0;
	for(int i=0; i<m*n; i++) {
		if(r==c[i]) {
			w=i+1;
		}
	}
	int l=0;
	if(w%n==0) {
		l=w/n;
	} else {
		l=w/n+1;
	}
	int h=0;
	int yu=w%n;
	if(l%2==0) {
		h=n+1-yu;
	} else {
		if(yu==0) {
			h=n;
		} else {
			h=yu;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
