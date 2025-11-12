#include<bits/stdc++.h>
using namespace std;
#define f(n,m,i) for(int i(n);i<=m;++i)
#define nf(n,m,i) for(int i(n);i>=m;--i)
#define dbug(x) cerr<<#x<<':'<<x<<' ';
#define ent cerr<<'\n';
using ll=unsigned int;
using li=long long;
ll min(ll x,ll y){  return x<y?x:y;}
ll max(ll x,ll y){  return x<y?y:x;}
ll gcd(ll a,ll b){  return b?gcd(b,a%b):a;}
void swp(ll &x,ll &y){  x^=y^=x^=y;}
const ll M(1000005),N(10005);
struct road{
	ll x,y,v;road(ll a=0,ll b=0,ll c=0){	x=a,y=b,v=c;}
	friend bool operator<(road a,road b){	return a.v<b.v;}
}cr[11][N],r[M];
ll n,m,k,x,y,z,c[11],fa[N+10],p[11],s[11],t,si,cnt(0),ch(0),mix;
li ans(1e18),res;
ll sk(ll x){	return fa[x]==x?x:fa[x]=sk(fa[x]);}
int main(){
	cout.tie(0),cin.tie(0)->sync_with_stdio(0);
	#ifndef MYDEBUG
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	#endif
	cin>>n>>m>>k,s[0]=0;
	f(1,m,i)	cin>>x>>y>>z,r[i]=road(x,y,z);
	sort(r+1,r+m+1);
	f(1,k,i){
		cin>>c[i];
		f(1,n,j)	cin>>x,cr[i][j]=road(n+i,j,x);
		sort(cr[i]+1,cr[i]+n+1);
	}
	f(1,n,i)	fa[i]=i;
	f(1,m,i){
		x=sk(r[i].x),y=sk(r[i].y);
		if(x^y){
			fa[y]=x,cr[0][++ch]=r[i],++cnt;
			if(cnt==n-1)	break;
		}
	}
	ll ul((1<<k)-1);
	f(0,ul,i){
		si=i,t=cnt=0,res=0,p[0]=1;
		f(1,k,j){
			if(si&1)	s[++t]=j,res+=c[j];
			si>>=1,p[j]=1;
		}
		if(res>=ans)	continue;
		f(1,n+k,j)	fa[j]=j;
		while(cnt<n+t-1){
			ch=-1,mix=2e9;
			f(0,t,j){
				while(p[j]<=n&&sk(cr[s[j]][p[j]].x)==sk(cr[s[j]][p[j]].y))	++p[j];
				if(p[j]<=n&&cr[s[j]][p[j]].v<mix)	ch=j,mix=cr[s[j]][p[j]].v;
			}
			fa[sk(cr[s[ch]][p[ch]].y)]=sk(cr[s[ch]][p[ch]].x),
			res+=cr[s[ch]][p[ch]].v,++p[ch];
			if(res>=ans)	break;
			++cnt;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';//dbug(clock()/1000000.0)
	return 0;
}
/*
ulimit -s 1000000
g++ -O2 -std=c++14 -static road.cpp -o road
./road
g++ -O2 -std=c++14 -static -Wall -Wextra -Wshadow -Wconversion -DMYDEBUG road.cpp -o road && echo ok
./road

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/