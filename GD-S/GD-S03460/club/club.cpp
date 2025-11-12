#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e6+10;
ll T,n,a[inf][5],cnt[6],s[inf],ans,tot,vis[inf];

bool cmp(ll a,ll b) {return a>b;}
ll maxn=-1;
void bfs(int x){
	if(x==n+1) {
		maxn=max(maxn,ans);
		return ;
	}
	for(ll j=1;j<=3;j++){
		if(cnt[j]+1>(n/2)) continue;
		cnt[j]++;
		ans+=a[x][j];
		bfs(x+1);
		cnt[j]--;
		ans-=a[x][j];
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	//cout<<"T="<<T<<endl;
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		scanf("%lld",&n);
		if(n<=200) {
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=3;j++) scanf("%lld",&a[i][j]);
			}
			bfs(1);
			printf("%lld\n",maxn);
			continue;
		}
		for(ll i=1;i<=n;i++) {
			for(ll j=1;j<=3;j++){
				ll u;
				scanf("%lld",&u);
				s[++tot]=u*100+i*10+j;
			}
		}
		sort(s+1,s+tot,cmp);
		//cout<<"!"<<s[1]<<endl;
		for(ll i=1;i<=tot;i++){
			ll jj=s[i]%10,ii=(s[i]/10)%10;
			//cout<<"i="<<i<<" cnt[jj]+1"<<cnt[jj]+1<<" vis[ii]"<<vis[ii]<<endl;
			if(cnt[jj]+1>(n/2)||vis[ii]==1) continue;
			vis[ii]=1;
			cnt[jj]++;
			ans+=s[i]/100;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
