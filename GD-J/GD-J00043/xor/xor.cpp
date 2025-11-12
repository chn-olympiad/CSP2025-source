#include<bits/stdc++.h>
using namespace std;
int n,k,a[514514],ans,sum[514514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int l1=1;
	for(int r=1;r<=n;r++){
		for(int l=l1;l<=r;l++){
			if((sum[r]^sum[l-1])==k){
				ans++;
				l1=r+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
