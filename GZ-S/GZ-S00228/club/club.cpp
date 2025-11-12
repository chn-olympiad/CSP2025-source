//GZ-S00228 北京师范大学贵阳附属中学 李昊阳
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int z = 0;
	int m = 0;
	cin>>m;
	for(int gg =0; gg < m; gg++) {
		int n = 0;
		cin>>n;
		for(int ff = 0; ff < n; ff ++) {

			int hgd[3] = {0};
			int db[3] = {0};
			for(int i = 0; i < 3; i++) {
				cin>>hgd[i];
			}
			int f = n / 2;
			int xb = -10001;
			int db1 = 0;
			for(int i = 0; i < 3; i ++) {
				if(hgd[i] > db1 && i != xb) {
					db1 = hgd[i];
					xb = i;
				}
			}
			int xb1 = -10001;
			int db2 = 0;
			int db3 = 0;
			if(db[xb] < f) {
				db[xb]++;
				z = z + hgd[xb];
			} else {
				for(int i = 0; i < 3; i++) {
					if(i != xb1 && hgd[i] > db2) {
						db2 = hgd[i];
						xb1 = i;
					}
				}
				if(db[xb1] < f) {
					db[xb1]++;
					z = z + hgd[xb1];
				} else {
					for(int i = 0; i < 3; i++) {
						if(i != xb1 && i != xb && hgd[i] < db3) {
							db3 = hgd[i];
							z = z + hgd[i];
						}
					}
				}
			}
		}
		cout<<z<<endl;
	}
}
