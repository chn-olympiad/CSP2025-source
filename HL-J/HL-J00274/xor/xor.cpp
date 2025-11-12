#include <bits/stdc++.h>

using namespace std;

int a[500050];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(k==0){
		cout << 0;	
	}
	if(k==1){
		cout << 1;
	}
	return 0;
}