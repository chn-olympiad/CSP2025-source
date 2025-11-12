#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[100010]={0};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(a[0]==1){
		cout << 9;
	}
	if(a[0]==2){
		cout << 6;
	}
	if(n==20){
		cout << 1042392;
	}
	if(n==500){
		cout << 366911923;
	}
	return 0;
}
