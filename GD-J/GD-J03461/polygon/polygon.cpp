#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int stick[3] = {};
	for (int i = 0; i < 3; i++){
		cin >> stick[i];
	}
	if ((stick[0] + stick[1] + stick[2]) > 2*max(max(stick[0],stick[1]),stick[2])){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0; 
	fclose("polygon.in");
	fclose("polygon.out");
} 
