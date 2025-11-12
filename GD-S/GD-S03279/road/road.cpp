#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+30,K=15,M=2e6+10;
struct node{
	int u,v,w;
}e[M],b[K][N],c[M],d[M];
int n,m,k,a[K],ans=1e18,cnt,fa[N],flag;
inline bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
}
inline void kru(int x,int y){
	int sum=0,tmp=0;
	for(int i=1;i<=n+y;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int fu=find(c[i].u),fv=find(c[i].v);
		if(fu!=fv){
			tmp++;
			fa[fu]=fv;
			sum+=c[i].w;
//			if(tmp>=y-1) break;
		}
	}
	ans=min(ans,sum+x);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>a[i];
		if(a[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>b[i][j].w;
			b[i][j].u=i+n,b[i][j].v=j;
		}
		sort(b[i]+1,b[i]+n+1,cmp);
	}
	if(!flag){
		for(int i=1;i<=m;i++) c[++cnt]=e[i];
		for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) c[++cnt]=b[i][j];
		sort(c+1,c+cnt+1,cmp);
		kru(0,k);
		cout<<ans<<endl;
		return 0;
	}
	for(int s=0;s<(1<<k);s++){
		cnt=0;
		int sum=0,tmp=n;
		for(int i=1;i<=m;i++) c[++cnt]=e[i];
		for(int i=1;i<=k;i++) if(s&(1<<i-1)){
			tmp++,sum+=a[i];
			int pc=1,pb=1,pd=1;
			while(pc<=cnt&&pb<=n){
				if(c[pc].w<b[i][pb].w) d[++pd]=c[pc++];
				else d[++pd]=b[i][pb++];
			}
			while(pc<=cnt) d[++pd]=c[pc++];
			while(pb<=n) d[++pd]=b[i][pb++];
			cnt=pd;
			for(int j=1;j<=cnt;j++) c[j]=d[j];
		}
		kru(sum,tmp);
	}
	cout<<ans<<endl;
	return 0;
}

