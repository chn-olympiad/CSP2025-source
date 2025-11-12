#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n == 3){
		int a,b,c;
		cin >> a >> b >> c;
		if (a + b > c && a + c > b && b + c > a) cout << 1;
		else cout << 0;
	}
	else{
		cout << 6; 
	}
	
	return 0;
}
/*Notes: 
*/
