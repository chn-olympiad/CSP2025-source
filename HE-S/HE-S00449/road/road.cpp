#include <iostream>
using namespace std;
int n, m, k;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if(k == 0){
		cout << 0 << endl;
		return 0;
	}
	
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
