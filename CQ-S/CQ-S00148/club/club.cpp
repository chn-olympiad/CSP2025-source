#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
namespace Aleister{
	int t,n;
	pair<int,int>a[MAXN][4];
	struct thing{
		int x,y,c;
	}b[MAXN];
	int tot,id;
	bool cmp(thing x,thing y){return x.c<y.c;}
	bool ccmp(pair<int,int>x,pair<int,int>y){return x.first>y.first;}
	int cnt[4],ans;
	int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		scanf("%d",&t);
		while(t--){
			scanf("%d",&n),cnt[1]=cnt[2]=cnt[3]=0,ans=0;
			for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1].first,&a[i][2].first,&a[i][3].first),a[i][1].second=1,a[i][2].second=2,a[i][3].second=3,sort(a[i]+1,a[i]+1+3,ccmp);
			for(int i=1;i<=n;i++) cnt[a[i][1].second]++,ans+=a[i][1].first/*,cerr<<"!"<<i<<' '<<a[i][1].first<<'\n'*/;
			for(int i=1;i<=3;i++) if(cnt[i]>cnt[id]) id=i;
//			cerr<<"@@@"<<ans<<' '<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<' '<<id<<'\n';
			if(cnt[id]<=(n>>1)){
				printf("%d\n",ans);
				continue;
			}
			tot=0;
			for(int i=1;i<=n;i++) if(a[i][1].second==id) b[++tot]=(thing){i,a[i][2].second,a[i][1].first-a[i][2].first};
			sort(b+1,b+1+tot,cmp);
			for(int i=1;i<=tot;i++){
				cnt[id]--;
				ans-=b[i].c;
				if(cnt[id]==(n>>1)) break;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main(){
	return Aleister::main();
}
//补佳乐~ 色普龙~ 螺内脂~
//这不花园路吗~ 
