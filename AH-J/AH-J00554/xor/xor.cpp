#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		ans+=a;
	}if(k==0) cout<<1;
	else cout<<ans;
}
