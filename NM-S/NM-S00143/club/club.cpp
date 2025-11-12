#include<bits/stdc++.h>
using namespace std;
int z[10005][3];

int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;

	cin>>t;
	int manyi[6];
	for (int i=0; i<t; i++) {
		int n;
		cin>>n;
        int l=0;

		for(int q=0; q<n; q++) {
			int c=0;
			for(int w=0; w<3; w++) {
				cin>>z[q][w];
			}
			if(z[q][0]>z[q][1]) {
				z[q][0]=z[q][0];
			}
			if(z[q][0]<z[q][1]) {
				z[q][0]=z[q][1];
			}
			if(z[q][0]>z[q][2]) {
				z[q][0]=z[q][0];
			}
			if(z[q][0]<z[q][2]) {
				z[q][0]=z[q][2];
			}

			c=z[q][0];
			l=l+c;


		}
        manyi[i]=l;


	}

         for(int s=0; s<t; s++)
		cout<<manyi[s]<<endl;


	return 0;

}
