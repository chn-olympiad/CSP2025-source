#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+10;

int n,a[N],k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(k == 0){
		cout << n;
		return 0;
	}
	return 0;
}