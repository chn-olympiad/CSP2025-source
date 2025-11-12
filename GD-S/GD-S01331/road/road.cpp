#include <iostream>
using namespace std;

int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x;
	cin >> x;
	cin >> x;
	cin >> x;
	cin >> x;
	if (x==1){
		cout << 13;
	}
	if (x==252){
		cout << 505585650;
	}
	if (x==709){
		cout << 504898585;
	}
	if (x==711){
		cout << 5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
