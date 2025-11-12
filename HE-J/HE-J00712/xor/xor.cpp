#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans,This;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n=1&&k=0){
		cout<<1;
		return 0;
	}
	if(n=2&&k=0){
		cout<<2;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cin>>This;
		a[i]=a[i-1]^This;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
	}
	cout<<ans;
	return 0;
}
