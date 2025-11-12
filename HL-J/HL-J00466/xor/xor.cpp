#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int p=0;
	int ans=0;
	for(int i=0;i<n;i++){
		p^=a[i];
		if(p==k){
			ans++;
			p=0;
		}
	}
	cout<<ans;
	return 0;
}
