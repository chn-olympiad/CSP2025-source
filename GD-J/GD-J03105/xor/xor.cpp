#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,K=1e3+5;
ll n,k,a[N];
ll axor[N],qj[K],bfr,ans;
//struct xr{
//	int l=0;
//	int r=0;
//}qj[M];
int solve(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		axor[i]=(axor[i-1]^a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((axor[j]^axor[i-1])==k)qj[j]=max(qj[j],i);
		}
	}
	for(int i=1;i<=n;i++){
		if(qj[i]!=0 && qj[i]>bfr)ans++,bfr=i;//,cout<<qj[i]<<" "<<i<<"\n";
	}
	printf("%lld",ans);
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
