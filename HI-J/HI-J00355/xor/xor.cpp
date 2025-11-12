#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f,pre[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]+pre[i-1];
		if(a[i]==k){
			f=i;
		}
	}
	long long l=1,r=f-1;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(r-mid>k){
			r=mid-1;
		}
		else if(r-mid==k){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<k;
	return 0;
}
