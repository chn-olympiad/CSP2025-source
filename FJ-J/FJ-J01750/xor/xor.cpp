#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x,ans=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		ans+=x;
	}
	if(k==0) cout<<ans/2;
	else if(k==1) cout<<ans;
	else cout<<2;
}
