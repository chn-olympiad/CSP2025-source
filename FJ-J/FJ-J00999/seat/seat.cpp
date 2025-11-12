#include<bits/stdc++.h>
using namespace std;
long long a[10000],n=0,m=0,R=0,hang=0,lie=0,temp=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+2);
	for(int i=n*m+1; i>1; i--) {
		if(a[i]==R) {
			temp=n*m-i+2;
			if(n%2==1) {
				if(temp%2==0) {
					if(temp%n==0) {
						lie=temp/n;
					} else {
						lie=temp/n+1;
					}
					if(temp%n==0) {
						hang=1;
					} else {
						hang=n+1-temp%n;
					}
					cout<<lie<<" "<<hang;
				} else {
					if(temp%n==0) {
						lie=temp/n;
					} else {
						lie=temp/n+1;
					}
					if(temp%n==0) {
						hang=n;
					} else {
						hang=temp%n;
					}
					cout<<lie<<" "<<hang;
				}
			} else {
				if(temp%2==1) {
					if((temp/n)%2==1) {
						hang=n+1-temp%n;
					} else {
						hang=temp%n;
					}
				} else {
					if(temp%n==0) {
						if((temp/n)%2==1) {
							hang=n;
						} else {
							hang=1;
						}
					} else {
						if((temp/n)%2==1) {
							hang=n+1-temp%n;
						} else {
							hang=temp%n;
						}
					}
				}
				if(temp%2==1) {
					lie=temp/n+1;
				} else {
					if(temp%n!=0) {
						lie=temp/n+1;
					} else {
						lie=temp/n;
					}
				}
				cout<<lie<<" "<<hang;
			}
		}
	}



	return 0;
}
