#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=5e3+5,A=5e3+1,mod=998244353;
int n,o,a[N];
LL ans,b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n,b[0]=1;
	for(rint i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(rint i=1;i<=n;++i){
		if(i>=3) for(rint j=a[i]+1;j<=A;++j){
			ans+=b[j];
			if(ans>=mod) ans-=mod;
		}
		for(rint j=A;j>=0;--j){
			o=a[i]+j;
			if(o>A) o=A;
			b[o]+=b[j];
			if(b[o]>=mod) b[o]-=mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
