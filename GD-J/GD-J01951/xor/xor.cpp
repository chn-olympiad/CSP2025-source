#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	int l=0,r=0;
	for(;l<n;l=r){
		if(a[l]==k) {
				ans++;
				r++;
				continue;
			}
			int cnt=a[l];
			r++;
		while(r<n&&cnt!=k){
			cnt=cnt^a[r];
			r++;
		}
		if(cnt==k) {
		ans++;
		r++;
	}
	}
	cout<<ans<<endl;
	return 0;
} 
