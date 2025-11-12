#include<bits/stdc++.h>
using namespace std;
struct ultra{
	int l,r;
}g[50000006];
int n,k,a[500006],sum[500006];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool is1=true,is1or0=true;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(a[i]!=1) is1=false;
	if(is1&&k==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++) if(a[i]>=2) is1or0=false;
	if(is1or0){
		int cnt1=0,cnt0=0;
		for(int i=1;i<=n;i++) if(a[i]==1) cnt1++;else cnt0++;
		if(k==0) cout<<cnt1/2+cnt0;
		else cout<<cnt1;
	}
	return 0;
}