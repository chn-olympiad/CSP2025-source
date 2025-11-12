#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[11][11]= {0};
	int n,m,w,t,s=1;
	cin>>n>>m;
	cin>>w;
	int f=n*m;
	for(int i=1; i<=n*m-1; i++) {
		cin>>t;
		if(w>t) f--;
	}
	for(int i=1; ; i++) {
		f-=n;
		if(f > n) {
			s++;
		} else {
			if(s%2=='0') {
				cout<<s<<' '<<f;
				return 0;
			} else {
				cout<<s<<' ';
				char b[20]= {0};
				int c=f;
				while(n--) {
					b[n]=b[n]*10+c%10;
					c/=10;
				}
				for(int j=strlen(b); ; j--) {
					if(b[j]==f) cout<<j;
				}

			}
		}
	}

	return 0;
}
