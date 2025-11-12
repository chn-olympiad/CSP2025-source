//GZ-S00409,许家霖，遵义四中
#include <bits/stdc++.h>
using namespace std;
int t;
struct em {
	int b;
	int c;
	int d;
	int ma;
};
int main() {
//	::freopen("club.in ","r",stdin);
//	::freopen("club.out ","w",stdout);
	cin>>t;
	for(int i=0; i<=t; i++) {
		int m,a=0;
		cin>>m;
		int dpart1=m/2,dpart2=m/2,dpart3=m/2;
		em x[m+1];
		for(int j=1; j<=m; j++) {

			cin>>x[j].b >>x[j].c >>x[j].d ;
			x[j].ma =max(x[j].b ,max(x[j].c ,x[j].d ));
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(x[j].ma <x[k].ma ){
					swap(x[j].b ,x[k].b );
					swap(x[j].c,x[k].c );
					swap(x[j].d ,x[k].d );
					swap(x[j].ma ,x[k].ma );
				}
			}
		}
		for(int j=1; j<=m; j++) {
			if(x[j].ma ==x[j].b ) {
				if(dpart1!=0) {
					dpart1--;
					a+=x[j].ma ;
				} else {
					a+=max(x[j].c ,x[j].d );
				}
			} else if(x[j].ma ==x[j].c ) {
				if(dpart2!=0) {
					dpart2--;
					a+=x[j].ma ;
				} else if(dpart2>=(m/2)){
					a+=max(x[j].c ,x[j].d );
				}
			} else if(x[j].ma ==x[j].d ) {
				if(dpart3!=0) {
					dpart3--;
					a+=x[j].ma ;
				} else if(dpart3>=(m/2)){
					a+= max(x[j].c ,x[j].b );
				}
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
