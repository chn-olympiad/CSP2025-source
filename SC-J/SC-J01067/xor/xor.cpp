#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,bol=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) bol=0;
	}
	int xorr=a[1],ans=0;
	for(int i=2;i<=n;i++){
		if(xorr==k){
			ans++;
			xorr=a[i];
			continue;
		}
		xorr^=a[i];
	}
	if(xorr==k){
		ans++;
	}
	cout<<ans;
	return 0;
}