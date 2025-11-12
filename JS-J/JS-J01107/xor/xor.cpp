#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,l=1,r=1;
long long a[500005],b[500005],vis[500005];
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(;l<=n;l++){
		for(;r<=n;r++){
			if((b[r]^b[l-1])==k){
				ans++;
				l=r;
				r=l+1;
				break;
			}
		}		
	}
	cout<<ans;
	return 0;
}
