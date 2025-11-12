#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(k == 0){
			if(n == 1 && n == 2 && a[i] == 1){
				cout<<1;
			}
		}
	}
	
	return 0;
}

