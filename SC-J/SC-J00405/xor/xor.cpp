#include<bits/stdc++.h>
using namespace std;
long long n,k,j=0;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int l=1;l<n;++l){
		for(int r=l;r<=n;++r){
			long long ans=a[l];
			for(int i=l+1;i<=r;++i){
				ans=ans^a[i];
			}
			if(ans==k){
				j++;
				cout<<l<<" "<<r<<'\n';
				l=r+1;
			}
		}
	}
	cout<<j;
	return 0;
}