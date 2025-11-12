#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100000;
int sz[3],bl[N+5],mx;
int n,a[N+5][3],ans,p[N+5],d[N+5],cur;
bool cmp(int i,int j){
	return d[i]<d[j];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=0;j<3;++j)
				scanf("%d",&a[i][j]);
		ans=0;
		memset(sz,0,sizeof sz);
		for(int i=1;i<=n;++i){
			int t=0;
			for(int j=1;j<3;++j)
				if(a[i][j]>a[i][t])t=j;
			bl[i]=t;++sz[t];
			ans+=a[i][t];
		}
		mx=-1;
		for(int i=0;i<3;++i)
			if(mx==-1||sz[i]>sz[mx])mx=i;
		if(sz[mx]<=n/2)printf("%d\n",ans);
		else{
			cur=0;
			for(int i=1;i<=n;++i)
				if(bl[i]==mx){
					p[++cur]=i;
					int tmp=0;
					for(int j=0;j<3;++j)
						if(j!=mx)tmp=max(tmp,a[i][j]);
					d[i]=a[i][mx]-tmp;
				}
			sort(p+1,p+cur+1,cmp);
			for(int i=1;i<=sz[mx]-n/2;++i)ans-=d[p[i]];
			printf("%d\n",ans);
		}
	}
	return 0;
}
