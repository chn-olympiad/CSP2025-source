#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,V=1e4,mod=998244353;
int n,a[N],f[N<<1],ans;ll cnt;
inline bool cmp(int x,int y){return x<y;}
inline void add(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);f[0]=1;
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int k=a[i]+1;k<=V;k++) sum+=f[k];
		ans=(ans+sum+cnt)%mod;
		cnt=cnt*2%mod;
		for(int k=V;k>=0;k--)
			if(k+a[i]>V) cnt+=f[k];
			else add(f[k+a[i]],f[k]);
		cnt%=mod;
	}cout<<ans;
	return 0;
}
