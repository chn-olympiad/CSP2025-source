#include<bits/stdc++.h>
using namespace std;
#define lbt(i) (i&(-i))
#define ll long long
#define __int __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define psb push_back
#define lbd lower_bound
#define pbd upper_bound
#define endl '\n'

const int mx=1e4+5;
int n,m,t,tg=1,fa[mx+10],a[15][mx];
vector<pair<int,pii>>e,g[1<<6],v;
ll s;

int fid(int x){
	return (fa[x]==x?x:fa[x]=fid(fa[x]));
}
bool mrg(int x,int y){
	if(fid(x)==fid(y)) return 0;
	fa[fa[x]]=fa[y];
	return 1;
}
int get(int x){
	int y=0;
	while(x){
		y+=(x&1);
		x>>=1;
	}
	return y;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int x,y,z,i=1;i<=m;i++){
		cin>>x>>y>>z;
		e.psb({z,{x,y}});
	}
	for(int i=1;i<=t;i++){
		bool f=0;
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j]) f=1;
		}
		tg&=f;
	}
	if(tg){
		for(int i=1;i<=t;i++){
			for(int j=1;j<=n;j++) e.psb({a[i][j],{i+n,j}});
		}
		for(int i=1;i<=n+t;i++) fa[i]=i;
		sort(e.begin(),e.end());
		for(int i=0,x=0;i<e.size();i++){
			if(mrg(e[i].S.F,e[i].S.S)) x++,s+=e[i].F;
			if(x==n+t-1) break;
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e.begin(),e.end());
	for(int i=0,x=0;i<e.size();i++){
		if(mrg(e[i].S.F,e[i].S.S)) g[0].psb(e[i]),x++,s+=e[i].F;
		if(x==n-1) break;
	}
	int fg=(1<<(t/2+1))-1;
	for(int i=1;i<(1<<t);i++){
		v.clear();
		ll c=0;
		int x=n+get(i),lst=(i>fg?(i&fg):(i-lbt(i)));
		for(int j=1;j<=t;j++){
			if(i&(1<<j-1)) c+=a[j][0];
			if((i-lst)&(1<<j-1)){
				for(int k=1;k<=n;k++) v.psb({a[j][k],{j+n,k}});
			}
		}
		for(int i=1;i<=n+t;i++) fa[i]=i;
		sort(v.begin(),v.end());
		for(int j=0,k=0,y=0;j<g[lst].size()||k<v.size(); ){
			if(j<g[lst].size()&&(k==v.size()||g[lst][j].F<=v[k].F)){
				if(mrg(g[lst][j].S.F,g[lst][j].S.S)){
					y++;
					c+=g[lst][j].F;
					if(i<=fg) g[i].psb(g[lst][j]);
				}
				j++;
			}else{
				if(mrg(v[k].S.F,v[k].S.S)){
					y++;
					c+=v[k].F;
					if(i<=fg) g[i].psb(v[k]);
				}
				k++;
			}
			if(y==x-1) break;
		}
		s=min(s,c);
	}
	cout<<s;
	return 0;
}
