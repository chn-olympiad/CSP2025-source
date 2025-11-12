#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N],reb[N],cs[N],cnt;

struct node{
	int x,y,z;
	bool f;
}ed[M+10*N];

bool cmp(node x,node y){
	return x.z<y.z;
}

int mf(int x){
	if(x==fa[x]) return x;
	return fa[x]=mf(fa[x]);
}

bool query(int x,int y){
	int ll=mf(x),rr=mf(y);
	if(ll==rr) return false;
	fa[rr]=ll;
	return true;
}

int bs=0,cc=0;
long long sum=0;
long long kru(){
	for(int i=1;i<=cnt;i++){
		if(query(ed[i].x,ed[i].y)){
			bs++;
			sum+=ed[i].z;
			if(ed[i].f) cs[ed[i].x]++;
			if(bs==n-1) return sum;
		}
	}
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>ed[i].x>>ed[i].y>>ed[i].z;
	
	cnt=m;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		reb[i]=x;
		for(int j=1;j<=n;j++){
			cin>>ed[++cnt].z;
			ed[cnt].x=i;
			ed[cnt].y=j;
			ed[cnt].z+=x;
			ed[cnt].f=true;
		}
	}
	
	sort(ed+1,ed+1+cnt,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	
	long long ans=kru();
	for(int i=1;i<=n;i++){
		if(cs[i]){
			ans-=1ll*(cs[i]-1)*reb[i];
			ans+=reb[i];
		}
	}
	cout<<ans;
	
	return 0;
}
