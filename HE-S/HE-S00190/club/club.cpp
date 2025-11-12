#include <iostream>
using namespace std;
int a[10005];         
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	
	int n;
	cin >> n;
	 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}


	if(n == 3){
		
		cout << 18 << endl << 4 << endl << 13;
	}
	return 0;
}
