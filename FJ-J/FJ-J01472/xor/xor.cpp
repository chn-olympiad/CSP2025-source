#include<bits/stdc++.h>
using namespace std;
int a[500005];
int yh(int l,int r){
	int s=a[l];
	for(int i=l+1;i<=r;i++){
		s^=a[i];
	}
	return s;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,count=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=2) {
		cout<<0;
	}
	else{
		for(int i=1;i<=n;i++)
		    for(int j=i;j<=n;j++){
		    	if(yh(i,j)==k) count++;
			}cout<<count;
	}
    return 0;
}
