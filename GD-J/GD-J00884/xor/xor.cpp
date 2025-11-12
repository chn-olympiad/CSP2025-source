#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,l,ans,x,sum,a[2000008],b[2000008];
main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) l++;
		if(a[i]==k) b[i]=1,ans++;
	}
	if(k==0&&l==n) return cout<<n/2,0;
	for(int i=1;i<=n;i++){
		if(b[i]==1) continue;
		sum=a[i]|x;
		if(sum==k){
			x=0,ans++,sum=0;
			continue;
		}
		x=a[i];
	}
	cout<<ans;
	return 0;
} 
