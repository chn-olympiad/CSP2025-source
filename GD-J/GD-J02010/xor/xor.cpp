#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5000005];
int cn1,cn0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k ;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] == 1) cn1 ++;
		if(a[i] == 0) cn0 ++;
	}
	if(k == 1){
		cout << cn1;
	}
	if(k == 0){
		cout << cn1 / 2 + cn0;
	}
	return 0;
}
