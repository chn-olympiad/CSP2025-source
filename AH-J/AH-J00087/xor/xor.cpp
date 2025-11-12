#include <bits/stdc++.h>
using namespace std;
const int max_=5e5+5;
int n,k,a[max_],f[max_];
int query(int l,int r){
	return (f[r]^f[l-1]);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	int ans=0,l=1,r=1;
	while(l<=n){
		while(r<=n){
			if(query(l,r)==k){
				ans++;
				break;
			}
			r++;
		}
		if(r==n+1){
			l++;
		}else{
			l=r+1;
		}
		r=l;
	}
	cout<<ans;
	return 0;
}
