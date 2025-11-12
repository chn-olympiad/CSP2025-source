#include<bits/stdc++.h>
using namespace std;
int h[5001];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1; i<=n; i++)cin >>h[i];
	if(n==3) {
		int mia=min(h[1],min(h[2],h[3]));
		if(mia==h[1]) {
			int mian=min(h[2],h[3]);
			if(mian==h[2]) {
				if(h[2]+h[1]>h[3]) {
					cout <<1;;
				} else {
					cout <<0;
				}
			}
			if(mian==h[3]) {
				if(h[3]+h[1]>h[2]) {
					cout <<1;
				} else {
					cout <<0;
				}
			}
		} else if(mia==h[2]) {
			int mian=min(h[1],h[3]);
			if(mian==h[1]) {
				if(h[2]+h[1]>h[3]) {
					cout <<1;
				} else {
					cout <<0;
				}
			}
			if(mian==h[3]) {
				if(h[3]+h[2]>h[1]) {
					cout <<1;
				} else {
					cout <<0;
				}
			}
		} else if(mia==h[3]) {
			int mian=min(h[1],h[2]);
			if(mian==h[1]) {
				if(h[3]+h[1]>h[2]) {
					cout <<1;
				} else {
					cout <<0;
				}
			}
			if(mian==h[2]) {
				if(h[3]+h[2]>h[1]) {
					cout <<1;
				} else {
					cout <<0;
				}
			}
		}
		return 0;
	}
	long long ans=0;
	for(int i=3; i<=n; i++) { //4997
		int a[n/i+1]= {0};
		int b[n/i+1]= {0};
		int s=0,mas=-1;
		int ansi=1;
		for(int j=1; j<=n; j++) { //5000
			s+=h[j];
			mas=max(mas,h[j]);
			if(j>=i) {
				a[ansi]=s;
				s-=h[j-i+1];
				b[ansi]=mas;
				if(mas==h[j-i+1]) {
					mas=-1;
					for(int x=j-i+2; x<=j; x++) {
						mas=max(mas,h[x]);
					}
				}
				ansi++;
			}
		}
		for(int j=1; j<=ansi-1; j++) {
			if(a[j]>b[j]*2) {
				ans++;
				cout <<a[j]<<" "<<b[j]<<endl;
				ans%=998244353;
			}
		}
		cout <<i<<endl;
	}
	cout <<ans;
	return 0;
}

