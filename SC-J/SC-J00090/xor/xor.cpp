#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],xr[500001];
long long f[500001];
long long lstk=-1;
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
		for(int j=i-1;j>=lstk;j--){
			long long nw=xr[i]^xr[j];
			if(nw==k){
				lstk=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}