#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m,n,v,k=0;
	int a,b,c,t;
	int s[100][100];
	cin>>m;
	for(int i=1; i<=m; i++) {
		cin>>n;
		v=n/2;
		for(int j=1; j<=n; j++) {
			cin>>s[i][1]>>s[i][2]>>s[i][3];

		}
		for(int d=1; d<=n; d++) {

			for(int y=1,h=3; y<=3,h>0; y++,h--) {
				for(int z=1; z<=n; z++) {
					a=a+s[z][y];
					b=b+s[z][h];


				}



			}
			if(a>b&&a>=t) {
				t=a;
			} else if(b>a&&b>=t) {
				t=b;
			}
			a=0;
			b=0;
		}
		cout<<t;
	}
	return 0;
}
