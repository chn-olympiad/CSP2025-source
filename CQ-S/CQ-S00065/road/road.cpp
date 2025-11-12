#include<stdio.h>
#include<algorithm>
#include<vector>
typedef long long ll;
const int N=1e5+5,M=2e6+5,Q=(1<<10);
auto lowbit = [](int x) -> int {return x&~x+1;};
struct node{
	int id,l,r,val;
	bool operator < (const node &x) const{return val<x.val;}
}e[M],b[N],c[N],d[N];
std::vector<int> v[Q];
int n,m,k,l[M],r[M],val[M],father[N];
ll sum[Q];
auto get = [](auto &&self,int t) -> int {return father[t]==t? t:father[t]=self(self,father[t]);};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].val);
	std::sort(e+1,e+m+1);
	for(int i=1;i<=n+k;i++) father[i]=i;
	ll now=0;
	for(int i=1;i<=m;i++){
		e[i].id=i,l[i]=e[i].l,r[i]=e[i].r,val[i]=e[i].val;
		int A=get(get,l[i]),B=get(get,r[i]);
		if(A!=B) father[B]=A,v[0].emplace_back(i),now+=val[i];
	}
	ll ans=now;
	for(int i=0;i<k;i++){
		scanf("%lld",&sum[1<<i]);
		for(int j=1;j<=n;j++) scanf("%d",&e[j].val),e[j].l=n+i+1,e[j].r=j;
		std::sort(e+1,e+n+1);
		for(int j=1;j<=n;j++){
			int num=i*n+m+j;
			l[num]=e[j].l,r[num]=e[j].r,val[num]=e[j].val;
		}
	}
	for(int s=1;s<(1<<k);s++){
		int low=lowbit(s);
		sum[s]=sum[low]+sum[s^low];
		int p=std::__lg(low),len1=0,len2=0,len3=0;
		for(auto i:v[s^low]) b[++len1]={i,l[i],r[i],val[i]};
		for(int i=1;i<=n;i++){
			int num=p*n+m+i;
			c[++len2]={num,l[num],r[num],val[num]};
		}
		int p1=1,p2=1;
		while(p1<=len1&&p2<=len2){
			if(b[p1].val<c[p2].val) d[++len3]=b[p1++];
			else d[++len3]=c[p2++]; 
		}
		while(p1<=len1) d[++len3]=b[p1++];
		while(p2<=len2) d[++len3]=c[p2++];
		for(int i=1;i<=n+k;i++) father[i]=i;
		now=0;
		for(int i=1;i<=len3;i++){
			int A=get(get,d[i].l),B=get(get,d[i].r);
			if(A!=B) v[s].emplace_back(d[i].id),father[B]=A,now+=d[i].val;
		}
		now+=sum[s];
		ans=std::min(ans,now);
	}
	printf("%lld",ans);
	return 0;
}
