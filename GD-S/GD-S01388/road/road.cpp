#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+3;
int n,m,k;
int f[N];
ll a[N];
struct node{
	int u,v;
	ll w;
	bool operator <(const node& x)const{
		return this->w<x.w;
	}
};
vector<node> g;
vector<ll> h;
int in(){
	int f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
int fid(int x){
	return f[x]==x?x:f[x]=fid(f[x]);
}
//inline con(){
//	freopen("con","w",stdout);
//	FILE* t=popen("fc road.out road3.ans","r");
//	char c[128];
//	while(fgets(c,sizeof(c),t))
//		printf("%s",c);
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(int i=0;i<m;++i)
		g.push_back({in(),in(),in()});
	for(int i=1;i<=n;++i)
		f[i]=i;
	int c,x,u,v,cnt=n-1;
	for(int i=0;i<k;++i){
		c=in();
		h.resize(1);
		for(int j=1;j<=n;++j){
			h.push_back(in());
			if(!h.back())
				x=j;
		}
		for(int j=1;j<=n;++j){
			if(j==x)
				continue;
			if(h[j])
				g.push_back({x,j,h[j]});
			else{
				u=fid(x),v=fid(j);
				if(u!=v){
					f[u]=v;
					--cnt;
				}
			}
		}
		h.clear();
	}
	sort(g.begin(),g.end());
	ll ans=0;
	for(node t:g){
		u=fid(t.u),v=fid(t.v);
		if(u==v)
			continue;
		f[u]=v;
		ans+=t.w;
		--cnt;
		if(!cnt)
			break;
	}
	printf("%lld\n",ans);
//	con();
	return 0;
}
