#include<bits/stdc++.h>
using namespace std;
struct edg{int s,e;long long w;}edge[2000005],start[2000005];
bool cmp(edg x,edg y){return x.w<y.w;}
long long zx[15][10005];
int cnt=0;
int fa[100005];
int getf(int x){
	if(fa[x]==x) return x;
	return fa[x]=getf(fa[x]); 
}
int kurscal(){
	sort(edge+1,edge+1+cnt,cmp);
	int ct=0;
	long long res=0;
	for(int i=1;i<=cnt;i++){
		int fs=getf(edge[i].s),fe=getf(edge[i].e);
		if(fs!=fe){
			fa[fs]=fe;
			ct++;
			res+=edge[i].w;
		}
		if(ct==cnt-1) break;
	}
	return res;
}
int n,m,k;
void Add(int cun){
	for(int i=2;i<=n+1;i++)
		edge[++cnt]={cun+n,i-1,zx[cun][i]};
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		start[++cnt]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>zx[i][1];
		for(int j=2;j<=n+1;j++) cin>>zx[i][j];
	}
	long long ans=LONG_LONG_MAX;
	for(int now=0;now<(1<<k);now++){
		int cun=0;
		long long res=0;
		cnt=0;
		for(int i=1;i<=m;i++) edge[++cnt]=start[i];
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int add=now;add;add>>=1){
			cun++;
			if((add&1)==1) Add(cun),res+=zx[cun][1];
		}
		if(res>ans) continue;
		res+=kurscal();
//		cout<<res<<" ";
		ans=min(res,ans);
//		cout<<bitset<8>(now)<<"!!\n";
//		for(int i=1;i<=cnt;i++){
//			cout<<edge[i].s<<" "<<edge[i].e<<" "<<edge[i].w<<"\n";
//		}
	}
	cout<<ans;

	return 0;
}
