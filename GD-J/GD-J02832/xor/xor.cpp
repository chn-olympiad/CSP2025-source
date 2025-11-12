#include<bits/stdc++.h>
using namespace std;
const int mn=5e5+1;
int n,k,a[mn],b[mn],i,ans;
int xxor(int x,int y){
	return (x|y)-(x&y);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
	}
	for(i=2;i<=n;i++){
		a[i]=xxor(a[i-1],a[i]);
	}
	for(i=1;i<=n;i++){
		if(xxor(a[i],a[i-1])==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
