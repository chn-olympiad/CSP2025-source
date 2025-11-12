#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a,b,c;
	if(n < 3){
		cin >> a >> b;
		cout << 0;
		return 0;
	}
	if(n == 3){
		int a,b,c;
		cin >> a >> b >> c;	
		int sum = a + b + c;
		int maxn = max(a,max(b,c));
		cout << (sum > (maxn * 2));
		return 0;
	}
	return 0;
} 
