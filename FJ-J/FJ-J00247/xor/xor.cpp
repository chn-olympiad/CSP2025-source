#include <bits/stdc++.h>
using namespace std;
int n,k,t[2000005],a[500005],p,ans,last=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++){
		p^=a[i];
		if((t[p^k]||(p^k)==0)&&t[p^k]>=last) ans++,last=i;
		t[p]=i;
	}
	cout<<ans;
	return 0;
}
