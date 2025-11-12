#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],maxn=-1;
int main(){
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		long long ans=a[l];
		for(int r=l+1;r<=n;r++){
			ans^=a[r];
			if(ans==k){
				maxn=max(maxn,r-l);
			}
		}
	}
	cout<<maxn;
	return 0;
}
