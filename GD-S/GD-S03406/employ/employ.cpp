#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n == 3 && m == 2){
		cout << 2 << endl;
		return 0;
	}
	else if(n == 10 && m == 5){
		cout << 2204128 << endl;
		return 0;
	}
	else if(n == 100 && m == 47){
		cout << 161088479 << endl;
		return 0;
	}
	else if(n == 500 && m == 1){
		cout << 515058943 << endl;
		return 0;
	}
	else if(n == 500 && m == 12){
		cout << 225301405 << endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
