#include"bits/stdc++.h"
using namespace std;
int n,k,a[500005],ans=0;
int s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==k) ++ans;
		s[i]=(s[i-1] ^ a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if((s[j] ^ s[i])==k) ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
