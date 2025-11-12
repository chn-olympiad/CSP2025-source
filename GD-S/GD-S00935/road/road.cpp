#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pair;
const ll N=10005,M=1000005;
ll pn,bn,cn,cnt,ans=1e18,first[N*2],dis[N*2],bj[N*2],jl[N],v[15];
priority_queue<Pair,vector<Pair>,greater<Pair> > q;
struct Bian{
	ll to,next,value;
}b[M*4];
ll read(){
	ll cnt=0;
	char c;
	for(c=getchar();c<'0' || c>'9';c=getchar());
	for(;c>='0' && c<='9';cnt=cnt*10+c-'0',c=getchar());
	return cnt;
}
void add(ll from,ll to,ll value){
	cnt++;
	b[cnt].to=to;
	b[cnt].value=value;
	b[cnt].next=first[from];
	first[from]=cnt;
}
void prim(ll cun){
	for(ll i=1;i<=pn+cn;i++){
		dis[i]=1e18;
		bj[i]=0;
	}
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.empty()==0){
		ll now=q.top().second;
		q.pop();
		if(bj[now]==1){
			continue;
		}
		bj[now]=1;
//		printf("[%lld %lld] ",now,cnt);
		cnt+=dis[now];
		for(ll i=first[now];i!=0;i=b[i].next){
			if(b[i].to>pn && (cun&(1<<(b[i].to-pn-1)))==0){
				continue;
			}
			if(dis[b[i].to]>b[i].value){
				dis[b[i].to]=b[i].value;
				if(bj[b[i].to]==0){
					q.push(make_pair(b[i].value,b[i].to));
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	pn=read();
	bn=read();
	cn=read();
	for(ll i=0;i<bn;i++){
		ll from=read(),to=read(),value=read();
		add(from,to,value);
		add(to,from,value);
	}
	for(ll i=1;i<=cn;i++){
		v[i]=read();
		for(ll j=1;j<=pn;j++){
			ll value=read();
			add(j,pn+i,value);
			add(pn+i,j,value);
		}
	}
	for(ll i=0;i<(1<<cn);i++){
//		printf("[%lld]\n",i);
		cnt=0;
		for(ll j=1;j<=cn;j++){
			if((i&(1<<(j-1)))!=0){
				cnt+=v[j];
			}
		}
		prim(i);
		ans=min(ans,cnt);
//		printf("\n");
	}
	printf("%lld",ans);
	return 0;
}
