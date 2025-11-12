#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
#define pii pair<int,int>
#define fi first
#define mp make_pair
#define se second
#define gc getchar()
#define pb push_back
using namespace std;
int n,m,k;
ll ans;
ll rd(){
	char c=gc;
	ll x=0;
	ll f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=gc;
	}
	while(isdigit(c)){
		x=(ll)x*10ll+c-'0';
		c=gc;
	}
	x*=f;
	return x;
}
struct bian{
	int x,y;
	ll v;
}_b[1000099],b[200099];
int cnt;
ll cun[20][10099];
int fa[20099];
ll c[20099];
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
bool cmp(const bian &x,const bian &y){
	return x.v<y.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,m){
		int x,y;
		ll v;
		x=(int)rd(),y=(int)rd(),v=rd();
		_b[i]=(bian){x,y,v};
	}
	FOR(i,1,k){
		c[i]=rd();
		FOR(j,1,n){
			cun[i][j]=rd();
		}
	}
	sort(_b+1,_b+1+m,cmp);
	int ltk=n;
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,m){
		if(ltk==1)break;
		int x=_b[i].x,y=_b[i].y;
		if(getfa(x)==getfa(y))continue;
		fa[getfa(x)]=getfa(y),--ltk;
		b[++cnt]=_b[i];
		ans+=_b[i].v;
	}
	FOR(i,1,k){
		FOR(j,1,n){
			b[++cnt]=(bian){i+n,j,cun[i][j]};
		}
	}
	sort(b+1,b+1+cnt,cmp);
	FOR(S,0,(1<<k)-1){
		FOR(i,1,n+k)fa[i]=i;
		ll _ans=0;
		int siz=0;
		FOR(i,1,k){
			if(S&(1<<(i-1))){
				_ans+=c[i],++siz;
			}
		}
		int ltk=n+siz;
		FOR(i,1,cnt){
			if(ltk==1)break;
			int x=b[i].x,y=b[i].y;
			if(x>n && (!(S&(1<<(x-n-1)))))continue;
			if(getfa(x)==getfa(y))continue;
			fa[getfa(x)]=getfa(y),_ans+=b[i].v,--ltk;			
		}
		ans=min(ans,_ans);
	}
	printf("%lld\n",ans);
	return 0;
}