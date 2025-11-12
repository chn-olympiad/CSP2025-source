#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[500050];
int s[500050];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int l=1,r=1;
	while(l<=r&&r<=n){
		if((s[r]^s[l-1])==k){
			ans++;
			l=r=r+1;
		}else{
			r++;
		}
	}
	cout<<ans;
	return 0;
} 