#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+14;
int n,m,k;
int vis[N];
const int M=1e6+1e5+4;
struct node{
	int u,v,w;
}e[M];
int f[N];
int c[N];
int o=0;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int kust1(){
	int sum=0,cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		f[fx]=fy;
		sum+=e[i].w;
		cnt++;
		if(cnt==n-1)return sum;
	}
}
int kust2(){
	int sum=0,cnt=0;
	int s=n;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		f[fx]=fy;
		if(e[i].u>n&&!vis[e[i].u])s++,vis[e[i].u]=1;
		sum+=e[i].w;
		cnt++;
		if(cnt==s-1)return sum;
	}
}
int r[20],rcnt;
int kust3(){
	int sum=0,cnt=0;
	int s=n;
	rcnt=0;
	memset(r,0,sizeof r);
	while(o){
		r[++rcnt]=o%2;
		o=o/2;
	}
	for(int i=1;i<=m;i++){
		if(e[i].u>n)if(!r[e[i].u-n])continue;
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		f[fx]=fy;
		if(e[i].u>n&&!vis[e[i].u]){
			if(r[e[i].u-n])s++,vis[e[i].u]=1;
		}
		sum+=e[i].w;
		cnt++;
		if(cnt==s-1)return sum;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int ans=kust1();
	for(int i=1;i<=n+k;i++)f[i]=i,vis[i]=0;
	int ff=0;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j])ff=1;
		for(int i=1;i<=n;i++){
			int ii;cin>>ii;
			e[++m].u=j+n,e[m].v=i,e[m].w=ii;
		}
	}
	sort(e+1,e+m+1,cmp);
	int ans2=kust2();
	for(int i=1;i<=k;i++){
		if(vis[i+n])ans2+=c[i];
		vis[i+n]=0;
	}
	if(ff==0)cout<<min(ans,ans2)<<"\n";
	else{
		int maxn=1e18;
		for(int s=0;s<(1<<k);s++){
			o=s;
			for(int i=1;i<=n+k;i++)f[i]=i;
			int ans1=kust3();
			for(int i=1;i<=k;i++){
				if(vis[i+n])ans1+=c[i];
				vis[i+n]=0;
			}
			maxn=min(maxn,ans1);
		}
		cout<<min(maxn,ans)<<"\n";
	}
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
