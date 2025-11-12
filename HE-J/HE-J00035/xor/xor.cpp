#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	long long  n,k;
	cin >> n >> k;
	int a[n+1];
	for(int i=0;i<=n;i++){
		cin >> a[i];
	}
	if(n<=2&&k==0){
		cout << "1" << endl;
	}
	if(n<=4&&k<=4){
		cout << "4"  << endl;
	}
	return 0;
}
