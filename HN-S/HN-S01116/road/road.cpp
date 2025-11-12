#include<bits/stdc++.h>
using namespace std;
double tt;
struct node{
	int l,r,val;
}t[200007],cs[1000007],a[20][10007];
int n,m,k;
long long ans=0x3f3f3f3f3f3f3f3f;
bool cmp(node a,node b){
	return a.val<b.val;
}
int fa[20007],c[20],flag[20];
int fd(int x){
	return x==fa[x]?x:fa[x]=fd(fa[x]);
}
void mer(int x,int y){
	x=fd(x),y=fd(y);
	if(x!=y) fa[x]=y;
}
void sv(){
	int cnt=n,now=1,dq[20]={1},cho=0;
	long long tot=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++) dq[i]=1;
	for(int i=1;i<=k;i++) if(flag[i]) cnt++,tot+=c[i];
	if(cnt==n) return ;
	while(now!=cnt){
		node tmp=t[dq[0]];cho=0;
		for(int i=1;i<=k;i++){
			if(!flag[i]||dq[i]==n) continue;
			if(tmp.val>a[i][dq[i]].val) cho=i,tmp=a[i][dq[i]];
		}
		dq[cho]++;
		if(fd(tmp.l)!=fd(tmp.r)){
			mer(tmp.l,tmp.r);
			now++;tot+=tmp.val;
		}
	}
	if(now==cnt) ans=min(ans,tot);
}
void dfs(int u){
	if(u==k+1){
		sv();
		return ;
	}
	dfs(u+1);
	flag[u]=1;
	dfs(u+1);
	flag[u]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>cs[i].l>>cs[i].r>>cs[i].val;
    sort(cs+1,cs+m+1,cmp);
    int tt=0;
    long long tot=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
    	int u=cs[i].l,v=cs[i].r;
    	if(fd(u)!=fd(v)){
    		mer(u,v);
    		t[++tt]=cs[i];tot+=cs[i].val;
		}
		if(tt==n-1) break;
	}
	if(tt==n-1) ans=tot;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].val,a[i][j].l=n+i,a[i][j].r=j;
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
t2ybb,1e3*1e4~5kaniba10s
give it more one second
it will change TLE to AC
*/
