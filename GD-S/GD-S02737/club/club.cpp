#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+3;
int T,n,a[N][3],pos[N],t[3],blen;
ll b[N];
void solve(){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int j=1;j<=2;j++) if(a[i][pos[i]]<a[i][j]) pos[i]=j;
		t[pos[i]]++,ans+=a[i][pos[i]];
	}
	int k=0;
	for(int j=1;j<=2;j++) if(t[j]>t[k]) k=j;
	if(t[k]>n/2){
		for(int i=1;i<=n;i++) if(pos[i]==k){
			if(k==0) b[++blen]=max(a[i][1],a[i][2])-a[i][k];
			if(k==1) b[++blen]=max(a[i][0],a[i][2])-a[i][k];
			if(k==2) b[++blen]=max(a[i][0],a[i][1])-a[i][k];
		}
		sort(b+1,b+1+blen,greater<ll>());
		for(int i=1;i<=blen && t[k]>n/2;i++) ans+=b[i],t[k]--;
	}
	printf("%lld\n",ans);
	blen=t[0]=t[1]=t[2]=0;
	for(int i=1;i<=n;i++) pos[i]=b[i]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
//14:46
