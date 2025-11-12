#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MN=1e4+5,MM=2e6+5,MST=(1<<10)+5;
int n,m,k;
typedef struct S{
	int u,v,w,st;
	bool operator <(const S &rhs)const{
		return w<rhs.w;
	}
}S;
S e[MM];
int elen;
int idx[MN];
int c[11];
int a[11][MN];
int findi(int o){
	if(idx[o]==o)return o;
	else return idx[o]=findi(idx[o]);
}
void hb(int u,int v){
	idx[findi(u)]=findi(v);
}
int kruscal(int st,int add){
	int ret=0;
	for(int j=0;j<=k;++j)
		for(int i=0;i<=n;++i)idx[i]=i;
	sort(e+1,e+elen+1);
	int cnt=0,i=0;
	while(cnt<n-1+add){
		++i;
		//printf("%d %d %d\n",st,e[i].st,(1<<(e[i].st-1)));
		//if(i>50)break;
		if(e[i].st!=0&&
			(!(st&(1<<(e[i].st-1))))
			)continue;
		if(findi(e[i].u)!=findi(e[i].v)){
			++cnt;
			hb(e[i].u,e[i].v);
			ret+=e[i].w;
		}
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].st=0;
	}
	elen=m;
//	bool A=true;
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		//if(c[i]!=0) A=false;
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			e[++elen].u=n+i;
			e[elen].v=j;
			e[elen].w=a[i][j];
			e[elen].st=i;
		}
	}
	// for(int i=1;i<=elen;++i){
	// 	printf("%d %d %d %d\n",e[i].u,e[i].v,e[i].w,e[i].st);
	// }
	// if(A){
	// 	elen=m;
	// 	for(int i=1;i<=k;++i){
	// 		for(int j=1;j<=n;++j){
	// 			e[++elen].u=n+i;
	// 			e[elen].v=j;
	// 			e[elen].w=a[i][j];
	// 		}
	// 	}
	// 	//printf("%d",kruscal(0));
	// 	return 0;
	// }
	int ans=0x3FFFFFFF;
	for(int i=0;i<(1<<k);++i){
		int nt=0,add=0;
		for(int j=0;j<k;++j){
			if(i&(1<<j)){
				nt+=c[j+1];
				++add;
			}
		}
		//printf("%d\n",nt);
		if(nt>=ans)continue;
		ans=min(ans,kruscal(i,add)+nt);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
