#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3){
		cout << 0;
		return 0;
	}
	int x,y,z;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		if(i == 1) x = t;
		if(i == 2) y = t;
		if(i == 3) z = t;
	}
	if(x + y + z > max({x,y,z})*2){
			cout << 1;
	}else{
			cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
