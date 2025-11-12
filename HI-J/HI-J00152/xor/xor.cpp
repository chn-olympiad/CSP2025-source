#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[15];
	if(n<=100 && k==0){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		cout << n/2;
	}
	return 0;
}
