#include <cstdio>
#include <functional>
#include <algorithm>

const int N=114514;

struct ifo{
	struct nod{int p,v;}a[3];
}a[N];

int c[3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);while(T--){
		int n,ans=0;scanf("%d",&n);c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;++i){
			for(int k=0;k<3;++k) scanf("%d",&a[i].a[k].v),a[i].a[k].p=k;
			std::sort(a[i].a,a[i].a+3,[](ifo::nod x,ifo::nod y){return x.v>y.v;});
		}
		std::sort(a+1,a+n+1,[](ifo x,ifo y){return x.a[0].v-x.a[1].v>y.a[0].v-y.a[1].v;});
		for(int i=1;i<=n;++i){
			if(++c[a[i].a[0].p]>n>>1) ans+=a[i].a[1].v;
			else ans+=a[i].a[0].v;
		}
		printf("%d\n",ans);
	}
}
