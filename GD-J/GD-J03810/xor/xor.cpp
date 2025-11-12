#include<bits/stdc++.h>
using namespace std;
long long a[500001],f[500001],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=(a[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=i-1;j>=0;j--){
			if((a[i]^a[j])==k){
				f[i]=max(f[i],f[j]+1);
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
} 
