#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t;
    int n;
    cin >> t;
    int ts[t];//结果 
    for (int i=0;i<t;i++){
    	cin >> n;
    	int b[n];
    	int a[3];
    	int aa[n];
    	int c[3];//人数
    	int d[3][100000];
    	ts[i] = 0;
    	if (n%2==0){
    		int y = 0;
    		int x = 0;
    		int z = 0;
			for (int iii =0;iii<n;){
				cin >> a[0] >>a[1] >> a[2];
				if (a[0]>=a[1] & a[0]>=a[2]){
    			b[iii] = 1;
    			aa[iii] = a[0];
			}else if (a[1]>=a[0] & a[1]>=a[2]){
    			b[iii] = 2;
    			aa[iii] = a[1];
			}else if (a[2]>=a[1] & a[2]>=a[0]){
    			b[iii] = 3;
    			aa[iii] = a[2];
			}else{
				break;
			}
			iii++;
			}
			for (int iii = 0;iii<n-1;){
				if (b[iii]==1){
					d[0][x] = aa[iii];
					x++;
				}
				if (b[iii]==2){
					d[1][y] = aa[iii];
					y++;
				}
				if (b[iii]==3){
					d[2][z] = aa[iii];
					z++;
				}
				iii++;
			}
			for (int iii =0;iii<=n/2;){
				ts[i]=d[0][iii]+d[1][iii]+d[2][iii]+ts[i];
				iii++;
			}
		}
	}
	for (int m=0;m<t-1;m++){
		cout << ts[m] << "\n";
	}
	cout << ts[t-1];
	return 0;
}


