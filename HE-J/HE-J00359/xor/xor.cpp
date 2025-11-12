#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	int n,m,a,k=0;

	int s[100][100];
	int l[100];	
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>s[i][j];

		}
	}
	a=s[1][1];

	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
			if(s[i][j]<s[i][j+1]) {
				k=s[i][j];
				s[i][j]=s[i][j+1];
				s[i][j+1]=k;
			}

			if(s[i][j]<s[i+1][j]) {
				k=s[i][j];
				s[i][j]=s[i+1][j];
				s[i+1][j]=k;
			}
				if(s[i][j]<s[i+1][j+1]) {
				k=s[i][j];
				s[i][j]=s[i+1][j];
				s[i+1][j]=k;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
		
			if(s[i][j]==a) {
				cout<<i<<" "<<j;
				break;
			}
		}
	}


	return 0;
}
