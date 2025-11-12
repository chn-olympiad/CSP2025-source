#include <iostream>
using namespace std;
int main(){
	long long ren,shuju,manyi[100],bu[100][2],zuida=0;
	cin>>shuju;
	for(int h=1;h<=shuju;h++){
	
		for(int i=0;i<ren-1;i++){
			for(int j=0;j<2;j++){
				cin>>bu[i][j];
			
			}
		}	
		for(int j=0;j<ren;j++){
				for(int c=0;c<2;c++){
					if(manyi[j]<bu[j][c]) {
						manyi[j]=bu[j][c];
						zuida+=manyi[j];
				}
			
			}
		}
		cout<<zuida;
	}
	return 0;
} 
