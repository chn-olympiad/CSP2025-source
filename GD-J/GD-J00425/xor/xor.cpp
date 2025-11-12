#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[50005],b[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
	int i=1,j=0,ans=0;
	while(j<=n&&i<=n){
		j++;
		if(j==n+1){
			i++;
			j=i-1;
		}
		if((b[j]^b[i-1])==k){
			ans++;
			i=j+1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
