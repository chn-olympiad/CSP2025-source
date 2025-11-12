#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans,a[N],b[N],c[N],cnta,cntb,cntc,p[N];
void sol(){
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=a[i],p[i]=max(b[i],c[i])-a[i];
	sort(p+1,p+n+1,greater<int>());
	for(int i=1;i<=n/2;i++) cnt+=p[i];
	ans=max(ans,cnt);
}
void solve(){
	scanf("%d",&n); ans=cnta=cntb=cntc=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]==max({a[i],b[i],c[i]})) cnta++,ans+=a[i];
		else if(b[i]==max({a[i],b[i],c[i]})) cntb++,ans+=b[i];
		else cntc++,ans+=c[i]; 
	}
	if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2) return printf("%d\n",ans),void();
	ans=0; sol(); swap(a,b); sol(); swap(a,c); sol();
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
} 
