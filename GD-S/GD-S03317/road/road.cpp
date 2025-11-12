#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10100;
int n,m,k,cnt,a,b,f[N];
LL ans,tmp,w[N],to[15][N];
struct AB{
	int x,y;
	LL w;
	bool operator<(const AB &o)const{
		return w<o.w;
	}
}l[N*100],rd[N*11];
int fnd(int x){
	if(f[x]==x)return x;
	return f[x]=fnd(f[x]);
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&l[i].x,&l[i].y,&l[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&to[i][j]);
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(l+1,l+m+1);
	for(int i=1;i<=m;i++){
		a=l[i].x,b=l[i].y;
		if(fnd(a)!=fnd(b)){
			f[f[a]]=f[b],ans+=l[i].w;
			l[++cnt]=l[i];
		}
	}
	for(int t=1;t<(1<<k);t++){
		tmp=0,cnt=n-1;
		for(int i=1;i<n;i++){
			rd[i]=l[i];
		}
		for(int i=1;i<=k;i++){
			if((t>>i-1)&1){
				tmp+=w[i];
				if(tmp>=ans)break;
				for(int j=1;j<=n;j++){
					rd[++cnt].x=n+i,rd[cnt].y=j;
					rd[cnt].w=to[i][j];
				}
			}
		}
//		cout<<tmp<<'*';
		if(tmp>=ans)continue;
		for(int i=1;i<=n+k;i++)f[i]=i;
		sort(rd+1,rd+cnt+1);
		for(int i=1;i<=cnt;i++){//cout<<rd[i].x<<' '<<rd[i].y<<' '<<rd[i].w<<endl;
			a=rd[i].x,b=rd[i].y;
			if(fnd(a)!=fnd(b)){
				f[f[a]]=f[b];
				tmp+=rd[i].w;//cout<<rd[i].w<<endl;
			}
			if(tmp>=ans)break;
		}
//		cout<<tmp<<endl;
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
