#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	if(k==1)cout<<ans;
	else cout<<n-ans;
	return 0;
}

