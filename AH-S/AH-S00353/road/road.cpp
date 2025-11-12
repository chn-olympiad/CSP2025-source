#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long u,v,id,w;
	bool operator < (const Node &rhs) const {
		return w<rhs.w;
	}
};
struct node{
	long long u,v;
	bool operator < (const node &rhs) const {
		return u<rhs.u;
	}
};
long long n,m,k,u,v,w,c[20],a[10010],tot,cnt;
bool b[20];
map<node,bool> f;
map<Node,bool> h;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	while(m--){
		scanf("%lld %lld %lld",&u,&v,&w);
		if(u>v) swap(u,v);
		h[{u,v,0,w}]=0;
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[j]);
			for(long long l=1;l<j;l++) h[{l,j,i,a[j]+a[l]}]=0;
		}
	}
	for(auto it=h.begin();it!=h.end();it++){
		Node num=it->first;
		if(!f[{num.u,num.v}]){
			f[{num.u,num.v}]=1;b[num.id]=1;
			tot++;cnt+=num.w;
			if(tot==n-1) break;
		}
	}
	for(long long i=1;i<=k;i++) if(b[i]) cnt+=c[i];
	printf("%lld",cnt);
	return 0;
}
