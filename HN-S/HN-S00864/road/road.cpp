#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
long long x,l1,l2,l,r,n,m,k,u,v,w,c[11],a[11][20100],d[11],e[11],f[20100],cnt,ans;
priority_queue<pair<long long,pair<long long,long long> > > q;
long long fu(int x){
	if(f[x]!=x){
		f[x]=fu(f[x]);
		return f[x];
	}
	else return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		q.push({-w,{u,v}});
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		f[i+n]=i+n;
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	cnt=n;
	while(cnt>1){
		u=q.top().second.first,v=q.top().second.second,w=-q.top().first;
		q.pop();
		f[v]=fu(v);
		f[u]=fu(u);
		if(f[u]==f[v]) continue;
		else{
			cnt--;
			f[v]=f[u];
			ans+=w;
		}
	}
/*	for(int i=0;i<1<<k;i++){
		x=i;cnt=1,tot=0;
		while(x){
			tot+=c[cnt]*(x%2);
			if(x%2){
				for(int j=1;j<=n;j++){
					
				}
			}
			x/=2;
			cnt++;
		}
	}*/
	printf("%lld",ans);
	return 0;
}
