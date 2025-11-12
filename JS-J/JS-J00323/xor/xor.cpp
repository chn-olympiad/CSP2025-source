#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[500006]={},b[500006]={},ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		//~ cout<<b[i]<<endl;
	}
	int l=1,r=1,ll=1;
	while(r<=n){
		for(l=ll;l<=r;l++){
			if((b[r]^b[l-1])==k){
				ans++;
				ll=r+1;
				break;
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
}
