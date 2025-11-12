#include<bits/stdc++.h>
using namespace std;
int a[500001],s[500001],f[500001],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((s[i]^s[j-1])==k){
				f[i]=max(f[j-1]+1,f[i]);
				break;
			}
		}
		f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n];
	return 0;
}
