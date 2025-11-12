#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
    	long long n;
    	cin >> n;
    	long long x[3][n],a = 0,b[3],c = 0,d = 0;
    	for(int j=0;j<n;j++){
    		for(int p=0;p<3;p++){
    			cin >> x[j][p];
    			b[p] = x[j][p];
			}
			c = b[0];
			for(int k = 0;k<2;k++){
				if(b[k]>c){
					c = b[k];
				}
			}
			//cout << c << endl << endl;
			sort(b,b+3);
			for(int k = 0;k<3;k++){
				if(c == b[2]){
					d++;
					//
					if(d/2 <= j/2){
						a+=b[2];
					}else{
						a+=b[1];
					}

				}
				c = 0;
			}
		}
		cout << a << endl;
		a = 0;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
