#include <bits/stdc++.h>
using namespace std;

int n; string c; int a[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	n=c.size();
	for(int i=0; i<n; i++){
		if(c[i]>='0'&&c[i]<='9') a[c[i]-'0']++;
	}
	for(int i=9; i>=0; i--){
		while(a[i]--) cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
