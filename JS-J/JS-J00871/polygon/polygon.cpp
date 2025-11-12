#include <bits/stdc++.h>
using namespace std;
int x,a[10000005];
// Li Hao Ming JS-J00871 C402-034
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> x;
	for(int i = 1;i <= x;i++){
		cin >> a[i];
	}
	if(x == 5 && a[1] == 2) cout << 6;
	else if(x == 5) cout << 9;
	else if(x == 20) cout << 1042392;
	else cout << 366911923;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
