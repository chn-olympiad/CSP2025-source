#include<bits/stdc++.h>
using namespace std;

const int N=1e4,M=1e6,K=10;
const long long inf=1e18;

struct qqq{
	int u,v,w;
}e0[M+5];
int len;

bool cmp(qqq q1,qqq q2){
	return q1.w<q2.w;
}

struct qqq2{
	int o;
	int u,v,w;
}e[M+5];

bool cmp2(qqq2 q1,qqq2 q2){
	return q1.w<q2.w;
}

int n,m,k;
int c[K+5];
int a[K+5][N+5];

int f[N+K+5];

void initf(){
	for(int i=1;i<=n+k;++i){
		f[i]=i;
	}
	return;
}

int grt(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=grt(f[x]);
	return f[x];
}

void ksk0(){
	initf();
	sort(e0+1,e0+m+1,cmp);
	len=0;
	for(int i=1;i<=m;++i){
		int fu=grt(e0[i].u),fv=grt(e0[i].v);
		if(fu!=fv){
			f[fu]=fv;
			++len;
			e[len].u=e0[i].u;
			e[len].v=e0[i].v;
			e[len].w=e0[i].w;
		}
		if(len==n-1){
			break;
		}
	}
	return;
}

int fg[K+5];

long long get_ans(int id){
	long long cnt=0;
	int ct=0;
	fg[0]=1;
	for(int i=0;i<K;++i){
		fg[i+1]=0;
		if((id&(1<<i))!=0){
			fg[i+1]=1;
			cnt+=c[i+1];
		}
	}
	initf();
	for(int i=1;i<=m;++i){
		if(fg[e[i].o]==0){
			continue;
		}
		int fu=grt(e[i].u),fv=grt(e[i].v);
		if(fu!=fv){
			f[fu]=fv;
			cnt+=e[i].w;
		}
		if(ct==n-1){
			break;
		}
	}
	return cnt;
}

long long solve(){
	ksk0();
	m=len;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			++m;
			e[m].u=n+i;
			e[m].v=j;
			e[m].w=a[i][j];
			e[m].o=i;
		}
	}
	sort(e+1,e+m+1,cmp2);
	long long ans=inf;
	for(int i=0;i<(1<<k);++i){
		ans=min(ans,get_ans(i));
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e0[i].u>>e0[i].v>>e0[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	cout<<solve();
	return 0;
}
