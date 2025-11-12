#include<bits/stdc++.h>
using namespace std;
int n,m,maax=-99999,p=1,o=1,q=0,oo=1;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	for(int i=0; i<=n*m; i++) {
		for(int j=1; j<=n*m-i; j++) {
			if(a[j]>maax) {
				maax=a[j];
				o=j;
			}
		}
		if(maax==a[1]){
			p=n*m-q-1;
			while(1){
				if(m%2==0) {
					if(p<n) {
						cout<<m<<" "<<p+1;
						return 0;
					}
					m--;
					p-=n;
				}
				if(m%2!=0) {
					if(p<n) {
						cout<<m<<" "<<n-p;
						return 0;
					}
					m--;
					p-=n;
				}
			}

		}
		q++;
		maax=-999;
		a[o]=0;
	}
	return 0;
}