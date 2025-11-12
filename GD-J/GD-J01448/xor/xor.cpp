#include<bits/stdc++.h>
#define N 500010
#define A 1048600
using namespace std;
int n,k,la[A],f[N],mx[N];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		sum^=x;
		int nw=sum^k;
		f[i]=f[i-1];
		if(la[nw]||nw==0){
			f[i]=max(mx[la[nw]]+1,f[i]);
		}
		la[sum]=i;
		mx[i]=max(mx[i-1],f[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
