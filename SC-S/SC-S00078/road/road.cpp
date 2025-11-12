#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
#define int ll
#define PII pair<int,int>
using namespace std;
const int maxn=1<<20;
char _in[maxn],*_p1=_in,*_p2=_in;
#define getchar() (_p1==_p2&&(_p2=(_p1=_in)+fread(_in,1,maxn,stdin),_p1==_p2)?EOF:*_p1++)
void read(int &x){
	x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
int T=1,n,m,k,cnt,c[30],a[30][10010],idx,res=1e18,ans,targ;
bool TaskA=1;
struct edge{
	int u,v,w;
};
set<edge>st,tmp;
int pre[10010],siz[10010];
int fnd(int x){
	if(pre[x]==x)return x;
	return pre[x]=fnd(pre[x]);
}
void join(int x,int y){
	x=fnd(x),y=fnd(y);
	if(x==y)return;
	if(siz[x]<siz[y])pre[x]=y,siz[y]+=siz[x];
	else pre[y]=x,siz[x]+=siz[y];
}
bool operator<(const edge& a,const edge& b){
	return a.w<b.w;
}
edge pp;
void solve(){
//	cin>>n>>m>>k;
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;i++){
//		cin>>e[i].u>>e[i].v>>e[i].w;
		read(pp.u);
		read(pp.v);
		read(pp.w);
		st.insert(pp);
	}
	for(int i=1;i<=k;i++){
//		cin>>c[i];
		read(c[i]);
		if(c[i]!=0)TaskA=0;
		for(int j=1;j<=n;j++){
//			cin>>a[i][j];
			read(a[i][j]);
			if(a[i][j]!=0)TaskA=0;
		}
	}
	if(TaskA&&k!=0){
//		cout<<"0\n";
		putchar('0');putchar('\n');
		return;
	}
	else if(k==0){
		for(int i=1;i<=n;i++)pre[i]=i,siz[i]=1;
//		sort(e+1,e+m+1,cmp);
		tmp=st;
		res=0;
		while(!tmp.empty()){//1000
			int u=(*tmp.begin()).u,v=(*tmp.begin()).v,w=(*tmp.begin()).w;
			tmp.erase(tmp.begin());
			if(fnd(u)==fnd(v))continue;
			cnt++;
			join(u,v);
			res+=w;
			if(cnt==n-1)break;
		}
		cout<<res;
	}
	else{
		for(int mask=0;mask<(1<<k);mask++){//32
			idx=m,ans=0,cnt=0,targ=0;
//			cerr<<"1";
//			tmp.clear();
			tmp=st;
//			cerr<<"2";
			for(int i=1;i<=n+k;i++)pre[i]=i,siz[i]=1;
			for(int i=0;i<k;i++){//5
				if(((mask>>i)&1)!=0)continue;
				ans+=c[i+1];
				targ++;
				for(int j=1;j<=n;j++){//1000
					pp.u=n+i+1;
					pp.v=j;
					pp.w=a[i+1][j];
					tmp.insert(pp);
				}
			}
//			sort(ne+1,ne+idx+1,cmp);//20000000
			while(!tmp.empty()){//1000
				int u=(*tmp.begin()).u,v=(*tmp.begin()).v,w=(*tmp.begin()).w;
				tmp.erase(tmp.begin());
				if(fnd(u)==fnd(v))continue;
				cnt++;
				join(u,v);
				ans+=w;
				if(cnt==n+targ-1||ans>res)break;
			}
			res=min(res,ans);
		}
		cout<<res;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cin>>T;
	while(T--)solve();
	sjh0626s code;
}
/*
先把48pts拿到
不知道什么的期望56pts
*/