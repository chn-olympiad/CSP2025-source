#include <bits/stdc++.h>
using namespace std;
int l,r,n,k,a[500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	for (int l=1;l<=n;l++){
		for (int r=l;l<=n;r++){
			for (int i=l;i<=r;i++){
				sum = a[i]^sum;
				cout << sum <<" ";
			}
		}
	}
	return 0;
} 
