#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],cnt[4];
struct node{
	int from,val;
}d[N];
int rnk(int i,int x){
	for(int j=1;j<=3;j++)if(x==a[i][j])return j;
}
int delta(int i,int p){
	int mi=2e9;
	for(int j=1;j<=3;j++)if(j!=p){
		mi=min(mi,a[i][p]-a[i][j]);
	}
	return mi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
			int mx=max({a[i][1],a[i][2],a[i][3]}),p=rnk(i,mx);
			cnt[p]++;
			d[i]={p,delta(i,p)};
			ans+=mx;
		}
		sort(d+1,d+n+1,[](node x,node y){return x.val<y.val;});
		int mx=max({cnt[1],cnt[2],cnt[3]}),k,p=0;
		for(int i=1;i<=3;i++)if(mx==cnt[i])k=i;
		while(mx>n/2){
			if(d[++p].from==k)mx--,ans-=d[p].val;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
