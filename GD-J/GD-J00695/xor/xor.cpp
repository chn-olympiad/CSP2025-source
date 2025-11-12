#include<bits/stdc++.h>
using namespace std;
int n,k,a[10086];

int main(){
	frepen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n>>k;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	cout << n-k;
	
	return 0;
}
