#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i] xor a[i-1];
	}
	int r=0,l;
	while(r<=n){
		l=r+1;
		for(r=l;r<=n;r++){
			if((a[r] xor a[l-1])==k){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
