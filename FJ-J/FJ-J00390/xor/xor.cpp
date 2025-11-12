#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll i,j,n,k,t,ans,a[N],s[N],f[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(scanf("%lld%lld",&n,&k),i=1;i<=n;scanf("%lld",&a[i]),s[i]=s[i-1]^a[i],i++);
	if(n<=5000){
		for(i=1;i<=n;i++) for(f[i]=(s[i]==k),j=1;j<i;j++) f[i]=max(f[j]+((s[i]^s[j])==k),f[i]);
		for(i=1;i<=n;ans=max(ans,f[i]),i++);
		return cout<<ans,0;
	}
	for(i=1;i<=n;i++){
		if(t==0&&s[i]==k) ans++,t=1;
		else if(t==1&&s[i]==0) ans++,t=0;
	}
	return cout<<ans,0;
}//60pts
