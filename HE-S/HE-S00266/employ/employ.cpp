#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n=0;
	int a,b,c,t;
	int s[1000];
	int h[1000];
	cin>>m>>n;


	for(int i=1; i<m; i++) {
		cin>>s[i];
		cin>>h[i];
}
	
		for(int d=1; d<=n; d++) {
			for(int y=1,h=3; y<=3,h>0; y++,h--) {
				for(int z=1; z<=n; z++) {
					a=a+s[z];
					b=b+s[z+1];


				}



			}
			if(a>b&&a>=t) {
				t=a;
			} else if(b>a&&b>=t) {
				t=b;
			}
		}
		cout<<t;
	
	return 0;
}
