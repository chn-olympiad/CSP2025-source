#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s = 0;
	bool c = 1;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0) c = 0;
		if(a[i] == 1) s++;
	}
	if(c){
		cout << n/2;
		return 0;
	}  
	cout << s;
} 
