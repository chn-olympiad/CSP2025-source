#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k,s,ans;
int a[1000086];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i] == k){
			s=0,ans++;
			continue;
		}
		s = a[i]^s;
		if(s == k) ans++,s=0;
	}
	cout<<ans;
	return 0;
} 
