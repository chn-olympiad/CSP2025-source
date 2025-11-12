#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0;
long long fa[10005];
struct q{
	long long u,v,w;
	
}a[1000005];
long long b[30][10];
bool cmp(q x,q y){
	return x.w<y.w;
}
int find(long long x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	long long ai=10000000000;
	for(int i=1;i<=k;i++){
		long long num=0;
		for(int j=1;j<=5;j++){
			num+=b[i][j];
		}
		ai=min(ai,num);
	}
	if(ai==0){
		cout<<0;
		return 0;
	}
	else{
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			long long x=find(a[i].u),y=find(a[i].v);
			if(x==y){
				continue;
			}
			else{
				long long ans=10000000000,r=0,o,p;
				for(int j=1;j<=k;j++){
					if(b[j][a[i].u]+b[j][a[i].v]+b[j][1]<ans){
						ans=b[j][a[i].u+1]+b[j][a[i].v+1]+b[j][1];
						r=j;
						
					}
				}
				if(ans<=a[i].w){
					b[r][1]=0;
					sum+=ans;
				}
				else sum+=a[i].w;
				fa[x]=y;
			}
		}
		cout<<sum;
	}
	return 0;
}
