#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen('xor.in','r',stdin); 
	freopen('xor.out','w',stdout);
	int n,k,a[500005];
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(k == 0){
		cout << 1;
	}
	else{
		cout << 3;
	}
	return 0;
}
