#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	int n,m,a,k=0;


	int l[100];	
	cin>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>l[i];

		}
	}
	

	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
			if(l[i]<l[i]) {
				k=l[i];
				l[i]=l[i];
				l[i]=k;
			}

			if(l[i]<l[i+1]) {
				k=l[i];
				l[i]=l[i+1];
				l[i+1]=k;
			}
				if(l[i]<l[i+1]) {
				k=l[i];
				l[i]=l[i+1];
				l[i+1]=k;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
		
			if(l[i]==a) {
				cout<<i;
				break;
			}
		}
	}


	return 0;
}
