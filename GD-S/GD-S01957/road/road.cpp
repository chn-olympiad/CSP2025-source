#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=1e4+10;
struct STU{
	ll from,to,time;
}e[N],line[N];
ll n,m,k,tot,a[11][M],fa[N],c[N],last_ans=0;
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(STU a,STU b){
	return a.time<b.time;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].from,&e[i].to,&e[i].time);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	last_ans=1e18;
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<(1<<k);i++){
		tot=0;
		ll ans=0;
		for(int j=1;j<=k;j++){
			if(((i>>(j-1))&1)==1){
				ans+=c[j];
				for(int l=1;l<=n;l++){
					tot++;
					line[tot]={j+n,l,a[j][l]};
				}
			}
		}
		sort(line+1,line+tot+1,cmp);
//		cout<<i<<":"<<ans<<endl;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		ll t1=1,t2=1;
		for(int j=1;j<=m+tot;j++){
			STU g;
			if(e[t1].time<line[t2].time||t2>tot)g=e[t1++];
			else g=line[t2++];
			ll tx=find(g.from),ty=find(g.to);
			if(tx!=ty){
//				cout<<line[j].from<<" "<<line[j].to<<' '<<line[j].time<<endl;
				ans=ans+g.time;
				fa[tx]=ty;
			}
		}
//		cout<<i<<":"<<ans<<endl;
		last_ans=min(last_ans,ans);
	}
	printf("%lld",last_ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
