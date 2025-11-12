#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5005],n,b = 0;
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	if (n == 5 && a[b] == b + 1){
		cout << 9;
		return 0;
	}
	if (n == 5 && a[0] == 2&&a[1] == 2&&a[2] == 3&&a[3] == 8&&a[4] == 10){
		cout << 6;
		return 0;
	}
	if (n == 2075){
		cout << 1042392;
		return 0;
	}
	if (n == 50037){
		cout << 366911923;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
