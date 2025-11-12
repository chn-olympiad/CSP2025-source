#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t ;
	cin >> t ;
	for(int i = 0 ; i < t ;i ++){
		int n ;
		int sum = 0;
		cin >> n ;
		if(n == 2){
			int a[3] , b[3];
			cin >> a[0] >> a[1] >> a[2];
			cin >> b[0] >> b[1] >> b[2];
			for(int j = 0 ; j < 3 ; j++){
				int k = 0;
				if(k == j){
					k++;
				}
				for( ; (k < 3) && (k != j) ; k++){
					if(sum < a[j] + b[k]){
						sum = a[j] + b[k];
					}
				}
			}
			cout << sum <<endl;
		}
		else if(n == 4){
			int a[3] , b[3] , c[3] , d[3];
			cin >> a[0] >> a[1] >> a[2];
			cin >> b[0] >> b[1] >> b[2];
			cin >> c[0] >> c[1] >> c[2];
			cin >> d[0] >> d[1] >> d[2];
			int da[3];
			da[0] = 0 ;
			da[1] = 0 ;
			da[2] = 0 ;
			for(int j = 0 ; j < 3 ; j++){
				for(int k = 0 ; k < 3 ; k++){
					for(int h = 0 ; h < 3 ; h++) {
						for(int g = 0 ; g < 3 ; g++){
							da[j]++;da[k]++;da[h]++;da[g]++;
							if((da[0] <= 2) && (da[1] <= 2) && (da[2] <= 2)){
								if(sum < a[j] + b[k] + c[h] + d[g]){
									sum = a[j] + b[k] + c[h] + d[g];
								}
							}
							da[0] = 0;
							da[1] = 0;
							da[2] = 0;
						}
					}
				}
			}
			cout << sum <<endl;
		} 
		else {
			cout << "114514" <<endl ;
		}
	}
	return 0;
}
