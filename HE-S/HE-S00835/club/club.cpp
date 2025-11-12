#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    int t, n, a1, a2, a3, r = 0;
    cin >> t >> n;
    for(int i = 1; i <= t; i++){
    	for(int j = 1; j <= n; j++){
    		int q = 0, w= 0, e = 0;
    		cin >> a1 >> a2 >> a3;
    		if(a1 > a2 && a1 > a3){
    			q = q+ 1;
    			r = r + a1;
			}
		    else if(a2 > a1 && a2 > a3){
			    w = w + 1;
			    r = r + a2;
			}
			else if(a3 > a1 && a3 > a2){
				e = e + 1;
				r = r + a3;
			}
		}
	}
	cout << r << endl;
	return 0;
}
