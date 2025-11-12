#include<bits/stdc++.h>
#define N 100010
using namespace std;
int T,n,a[N][5],b[N],cnt[5],ans;
struct node { int delta,idx,club; };
vector<node> d;
bool cmp(node x,node y) { return x.delta>y.delta; }
void work(){
	cnt[1]=cnt[2]=cnt[3]=0; ans=0;
	d.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	for(int i=1;i<=n;++i){
		int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
		ans+=maxn;
		if(a[i][1]==maxn) b[i]=1,++cnt[1];
		else if(a[i][2]==maxn) b[i]=2,++cnt[2];
		else b[i]=3,++cnt[3];
	}
//	printf("Now ans = %d\n",ans);
//	for(int i=1;i<=n;++i) printf("%d ",b[i]); puts("");
	int maxn=max(cnt[1],max(cnt[2],cnt[3]));
	if(maxn<=(n>>1)){
		printf("%d\n",ans);
		return ;
	}
	if(cnt[1]==maxn){
		for(int i=1;i<=n;++i){
			if(b[i]!=1) continue;
			d.push_back((node){a[i][2]-a[i][1],i,2});
			d.push_back((node){a[i][3]-a[i][1],i,3});
		}
		sort(d.begin(),d.end(),cmp); int m=d.size();
		for(int i=0;i<m;++i){
			if(b[d[i].idx]!=1) continue;
			ans+=d[i].delta;
			b[d[i].idx]=d[i].club;
			--cnt[1], ++cnt[d[i].club];
			if(cnt[1]<=(n>>1)) break;
		}
	}else if(cnt[2]==maxn){
		for(int i=1;i<=n;++i){
			if(b[i]!=2) continue;
			d.push_back((node){a[i][1]-a[i][2],i,1});
			d.push_back((node){a[i][3]-a[i][2],i,3});
		}
		sort(d.begin(),d.end(),cmp); int m=d.size();
//		for(int i=0;i<m;++i) printf("(%d, %d, %d)\n",d[i].delta,d[i].idx,d[i].club);
		for(int i=0;i<m;++i){
			if(b[d[i].idx]!=2) continue;
			ans+=d[i].delta;
			b[d[i].idx]=d[i].club;
			--cnt[2], ++cnt[d[i].club];
			if(cnt[2]<=(n>>1)) break;
		}
	}else{
		for(int i=1;i<=n;++i){
			if(b[i]!=3) continue;
			d.push_back((node){a[i][1]-a[i][3],i,1});
			d.push_back((node){a[i][2]-a[i][3],i,2});
		}
		sort(d.begin(),d.end(),cmp); int m=d.size();
		for(int i=0;i<m;++i){
			if(b[d[i].idx]!=3) continue;
			ans+=d[i].delta;
			b[d[i].idx]=d[i].club;
			--cnt[3], ++cnt[d[i].club];
			if(cnt[3]<=(n>>1)) break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	return 0;
}