#include<bits/stdc++.h>
using namespace std;
int x[50005];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n;cin >> n;
	for(int i = 0;i < n;i++) cin >> x[i];
	sort(x , x + n);
	if(n < 3) cout << 0;
	else if(n == 3 && x[0] + x[1] > x[2]) cout << 1;
	else if(n == 3) cout << 0;
	fclose(stdin);
	fclose(stdout);
}