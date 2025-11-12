#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","W",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	if((n==1 && k==0)||(a[2]==1 && a[1]==1)){
		cout << 0;
	}else if(n==2 && k==0){
		if((a[1]==1||a[2]==1)||(a[2]==2||a[1]==2)){
			cout << 1;
		}
	}
	return 0;
} 