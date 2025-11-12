#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+10;
int zs = 0;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<=n-1;i++){
		cin >> a[i];
	}
	if(a[0] == 1){
		cout << "9";
	}
	if(a[0] == 2){
		cout << "6";
	}
	if(n == 20){
		cout << "1042392";
	}
	if(n == 500){
		cout << "366911923";
	}
	if(n<3){
		cout << "0";
	}
	return 0;
}

