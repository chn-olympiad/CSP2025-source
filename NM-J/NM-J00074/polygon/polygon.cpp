#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a1,a2,a3,max1;
	cin >> a1 >>a2 >>a3;
	max1 = max(a1,max(a2,a3));
	if(a1 + a2 + a3 > 2 * max1) cout <<1;
	else cout << 0;
	return 0;
}
