#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 20005
#define MAXM 2000005

int n,m,k;
long long c[15],a[15][MAXN];
long long ans;

int fa[MAXN];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void unite(int u,int v) {fa[find(u)]=find(v);}

int tot;

struct edge{
	int u,v;
	long long w;
	int flag;
	bool operator <(const edge &a)const{return w<a.w;}
}e[MAXM];

long long kruskal(int sum,int st){
	long long ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1,cnt=0;i<=tot;i++){
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		int flag=e[i].flag;
		if(flag&&!(st>>(flag-1)&1)) continue;
		if(find(u)==find(v)) continue;
		unite(u,v);
		ans+=w;
		cnt++;
		if(cnt==sum-1) return ans;
	}
}

void subtask1(){//k=0
	sort(e+1,e+tot+1);
	ans=kruskal(n,0);
	cout<<ans;
}

int bitcnt(int num){
	int cnt=0;
	while(num){
		if(num&1) cnt++;
		num>>=1;
	}
	return cnt;
}

void subtask2(){//k<=5
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++tot]={n+1,j,a[i][j],i};
		}
	}
	sort(e+1,e+tot+1);
	ans=1e18;
	for(int i=0;i<(1<<k);i++){
		long long tmp=0;
		for(int j=1;j<=k;j++){
			if(i>>(j-1)&1) tmp+=c[j];
		}
		ans=min(ans,kruskal(n+bitcnt(i),i)+tmp);
	}
	cout<<ans;
}

void subtask3(){//A
	for(int i=1;i<=k;i++){
		int s=0;
		for(int j=1;j<=n;j++){
			if(!a[i][j]){
				s=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(j==s) continue;
			e[++tot]={s,j,a[i][j]};
		}
	}
	sort(e+1,e+tot+1);
	ans=kruskal(n,0);
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot]={u,v,w};
	}
	bool flag1=true;
	bool flag2=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag1=false;
		bool flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j]) flag=true;
		}
		flag2&=flag;
	}
	if(k==0) subtask1();
	else if(flag1&&flag2) subtask3();
	else subtask2();
	return 0;
}