#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500050],f[500050],b[1008][1008],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];b[i][i]=a[i];
	}
	for(ll i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			b[j][i]=b[j][i-1]^b[i][i];
		}
	}
	if(b[1][1]==k) f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			f[i]=max(f[i],f[j]);
			if(b[j+1][i]==k) f[i]=max(f[i],f[j]+1);
		}
	}
	cout<<f[n];
	return 0;
}

