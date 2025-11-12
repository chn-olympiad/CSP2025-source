#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],f[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		if ((a[i]^a[i-1])==k){
			f[i]++;
		}
		else{
			for (int j=i-1;j>=1;j--){
				if ((a[i]^a[j-1])==k){
					f[i]=max(f[i],f[j-1]+1);
					break;
				}
			}	
		}
	}
	cout<<f[n];
	return 0;
} 