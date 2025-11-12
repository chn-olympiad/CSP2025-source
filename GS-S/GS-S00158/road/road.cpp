#include <iostream>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int T = 100;
	cin>>T;
	long double a = 1.5;
	long double b = 1;
	while(T--) {
		if((a+b)*(a+b)/4  >2) {
			a = (a+b)/2;
		}
		if((a+b)*(a+b)/4  <=2) {
			b = (a+b)/2;
		}
	}
	cout<<(a+b)/2;
	return 0;

}
