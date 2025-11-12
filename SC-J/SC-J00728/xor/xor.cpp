#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],qzxor[500010],ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzxor[i]=qzxor[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int lll=0,j=i;
		for(int l=j;l<=n&&j<=n;l++){
			if((qzxor[j-1]^qzxor[l])==k){
				lll++;
				j=l+1;
			}
		}
		ans=max(ans,lll);
	}
	cout<<ans;
	return 0;
}