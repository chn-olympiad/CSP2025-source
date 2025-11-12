#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	if(n < 3){
		cout << 0;
		return 0;
	}
	cin >> a >> b >> c;
	int manx = max(a,max(b,c));
	if(a + b + c >2*manx)cout <<1;
	else cout << 0;
	return 0;
}