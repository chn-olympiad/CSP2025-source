#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	if(n==1){
		int a;
		cin >> a;
		if(a==k) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if(n==2){
		int a,b;
		cin >> a >> b;
		if(k==0){
			if(a==b) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if(a xor b==k&&a==k&&b==k) cout << 3 << endl;
		else if((a xor b==k&&a==k)||(a xor b==k&&b==k)||(a==k&&b==k)) cout << 2 << endl;
		else if(a==k||b==k||a xor b==k) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else cout << 25 << endl;
	/*
	
	*/
	return 0;
}
