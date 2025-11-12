#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=12;
int n,m,k,cnt;
int f[N];
int num[K],c[K],d[K];
long long ans=1e18,sum;
struct node{
	int u,v,w;
}st[M],st2[K][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>st[i].u>>st[i].v>>st[i].w;
	sort(st+1,st+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(st[i].u)!=find(st[i].v)){
			f[find(st[i].u)]=find(st[i].v);
			st[++cnt]=st[i];
			sum+=st[cnt].w;
		}
	}
	for(int i=1;i<=k;i++){
		num[i]=n;
		cin>>c[i];
		for(int j=1;j<=n;j++){
			st2[i][j].u=i+n;
			st2[i][j].v=j;
			cin>>st2[i][j].w;
		}
		sort(st2[i]+1,st2[i]+n+1,cmp);
		while(num[i]&&st2[i][num[i]].w>st[cnt].w) num[i]--;
	}
	for(int i=0,mi,ma;i<(1<<k);i++){
		for(int j=1;j<=k;j++) d[j]=1;
		sum=0;
		int now=1,res=0;
	    for(int j=1;j<=k;j++) if(i&(1<<(j-1))) sum+=c[j];
	    for(int j=1;j<=k;j++) if(i&(1<<(j-1))) res++;
	    for(int i=1;i<=n+k;i++) f[i]=i;
	    for(int j=1;j<n+res;j++){
	    	while(find(st[now].u)==find(st[now].v)&&now<=cnt) now++;
	    	ma=st[now].w;
	        mi=0;
	    	if(now>cnt) ma=2e9;
			for(int v=1;v<=k;v++){
				if(i&(1<<(v-1))){
					while(find(st2[v][d[v]].u)==find(st2[v][d[v]].v)&&d[v]<=num[v]) d[v]++;
					if(st2[v][d[v]].w<ma&&d[v]<=num[v]){
						ma=st2[v][d[v]].w;
						mi=v;
					}
				}
			}
			if(!mi) f[find(st[now].u)]=find(st[now].v);
			else f[find(st2[mi][d[mi]].u)]=find(st2[mi][d[mi]].v);
			sum+=ma;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
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
