#include <bits/stdc++.h>
using namespace std;
int n,k,s,xorr,last=-1;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		xorr=0;
		for(int j=i;j>=0;--j){
			if(j==last){
				break;
			}
			xorr=(xorr xor a[j]);
			if(xorr==k){
				++s;
				last=i;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
