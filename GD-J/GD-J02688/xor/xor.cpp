#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int n,k,t,cnt=1,a[M],ans,s[M],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int l=1,r=1;
	while (l<=r&&r<=n){
		if (a[r]==k){
			ans++;
			l=r+1;
			r=l;
			sum=0;
			continue;
		}
		if (sum<k) {
			sum^=a[r];
			r++;
		}
		else if (sum>k){
			sum=s[r]-s[l];
			l++;
		}
		else if (sum==k&&r-l!=0){
			ans++;
			sum=0;
			l=r+1;
			r=l;
		}
		else {
			l=r+1;
			r=l;
		}
	}
	if (sum==k&&r-l!=0) ans++;
	cout<<ans;
	return 0;
}
