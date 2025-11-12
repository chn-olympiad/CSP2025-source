#include <iostream>
using namespace std;
int a,b,k;
int s[101][101];
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> a >> b;
	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			cin >> s[i][j];
		}
	}
	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			if(i==1&&j==1) {
				k=s[i][j];
			}
			if(s[i][j]>=s[i+1][j]) {
				swap(s[i][j],s[i+1][j]);
			}
			if(s[i][j]>=s[i][j+1]) {
				swap(s[i][j],s[i][j+1]);
			}
			if(s[i][j]>=s[i+1][j+1]) {
				swap(s[i][j],s[i+1][j+1]);
				if(i==a||j==b) {
					for(int x=1; x<=a; x++) {
						for(int y=1; y<=b; y++) {
							if(s[x][y]==k)
								cout << x << " " << y;
						}
					}

				}
			}

		}

	}
}

