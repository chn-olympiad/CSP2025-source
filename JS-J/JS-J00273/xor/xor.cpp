#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],k,n,lat=1,ans;
int xor_sum(int l,int r){
	if(r<l) swap(r,l);
	int q=a[l];
	for(int i=l+1;i<=r;i++) q^=a[i];
	return q;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int r=1;r<=n;r++)
	for(int l=lat;l<=r;l++)
	if(xor_sum(l,r)==k){
		ans++,lat=r+1;
		break;
	}
	cout<<ans;
	return 0;
}
