#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
};
long long n,m,k,u,v,w,a[15],mi[15]={1},fa[10015],x,s,mn=0x3f3f3f3f3f3f3f3f,b,ft[15],fx;
vector<node> mp;
bool cmp(const node &x,const node &y){
	return x.w<y.w;
}
long long get(long long x){
	if(fa[x]!=x) fa[x]=get(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=k;i++) mi[i]=2*mi[i-1];
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		mp.push_back({u,v,w});
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&b);
			mp.push_back({n+i,j,b});
			if(!a[i]&&!b){
				if(!ft[i]) fx++;
				ft[i]=1;
			}
		}
	}
	sort(mp.begin(),mp.end(),cmp);
	for(long long i=0;i<mi[k];i++){
		if(fx==k) i=mi[k]-1;
		x=n-1;
		s=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		long long f=i;
		for(int j=1;j<=k;j++){
			x+=f%2;
			s+=a[f%2*j];
			f/=2;
		}
		for(long long j=0;j<mp.size();j++){
			if((mp[j].u<=n||i/mi[mp[j].u-n-1]%2)&&(mp[j].v<=n||i/mi[mp[j].v-n-1]%2)){
				long long xu=get(mp[j].u),xv=get(mp[j].v);
				if(xu!=xv){
					s+=mp[j].w;
					fa[xu]=xv;
					x--;
					if(!x) break;
				}
			}
		}
		mn=min(mn,s);
	}
	printf("%lld",mn);
	return 0;
}
