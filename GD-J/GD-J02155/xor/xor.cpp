#include <bits/stdc++.h>
using namespace std;
int n,k,ans,p,psk;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>p;
		if(p==k){
			psk=0;
			ans++;
		}else if(psk^p==k){
			psk=0;
			ans++;
		}else psk^=p;
	}cout<<ans;
}
