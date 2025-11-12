#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define MN 10100
#define MM 1001000
#define MK 15
#define ll long long

struct ed{
	int f,t;ll v;
	friend bool operator <(const ed&a,const ed&b){
		return a.v<b.v;
	}
}sve[MK][MN],dp[1<<10][MN],sv[MM],cpy[MN<<2];

int ct[1<<10];
ll co[MK];
int n,m,k;
int fa[MN],siz[MN],lw[1<<11];
void ini(){
	for(int i = 1;i<=n+k;i++)fa[i]=i,siz[i]=1;
}
int zd(int x){
	if(fa[x]==x)return x;
	return fa[x]=zd(fa[x]);
}
void hb(int x,int y){
	x = zd(x);y = zd(y);
	if(x==y)return ;
	if(siz[x]>siz[y])swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}

ll cl(ed s1[],ed s2[],ed t[],int len1,int len2,int&len3){
	int l = 1,r = 1;
	s1[len1+1].v=0x3f3f3f3f;
	s2[len2+1].v=0x3f3f3f3f;
	int ccb = 0;
	ll res = 0;
	ini();
	while(l<=len1&&r<=len2){
		if(s1[l].v<s2[r].v){
			ed&e = s1[l];
			if(zd(e.f)!=zd(e.t)){
				hb(e.f,e.t);
				res+=e.v;
				t[++ccb]=e;
			}
			l++;
		}
		else{
			ed&e = s2[r];
			if(zd(e.f)!=zd(e.t)){
				hb(e.f,e.t);
				res+=e.v;
				t[++ccb]=e;
			}
			r++;
		}
	}
	len3=ccb;
	return res;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	
//	int ff,tt;ll vv;
	
	for(int i = 1;i<=m;i++){
		cin>>sv[i].f>>sv[i].t>>sv[i].v;
	}
	sort(sv+1,sv+1+m);
	ll res = 0,ans = 0x3f3f3f3f3f3f3f3fll;
	ini();
	for(int i = 1;i<=m;i++){
		if(zd(sv[i].f)!=zd(sv[i].t)){
			hb(sv[i].f,sv[i].t);
			res+=sv[i].v;
			dp[0][++ct[0]]=sv[i];
		}
	}
//	cerr<<0<<' '<<res<<'\n';
	ans = min(ans,res);
	for(int i = 1;i<=k;i++){
		cin>>co[i];
		for(int j = 1;j<=n;j++){
			cin>>sve[i][j].v;
			sve[i][j].f=n+i;
			sve[i][j].t=j;
		}
		sort(sve[i]+1,sve[i]+1+n);
	}
	lw[0]=-1;
	for(int  i = 1;i<(1<<k);i++){
		int j = lw[i]=(i&1)?0:(lw[i>>1]+1);
		res = cl(dp[i^(1<<j)],sve[j+1],dp[i],ct[i^(1<<j)],n,ct[i]);
		for(int l = 0;l<k;l++)if((i>>l)&1)res+=co[l+1];
		ans = min(ans,res);
//		cerr<<i<<' '<<j<<' '<<res<<'\n';
	}
	cout<<ans;
	
	return 0;
}

