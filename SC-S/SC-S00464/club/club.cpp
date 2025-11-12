#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
int q[4][MAXN],cnt[4];
long long ans;
struct Akano{
	int x[4];
	void update(){
		int f,s;
		if(x[1]>=x[2] && x[1]>=x[3]){
			f=1;
			if(x[2]>x[3])s=2;
			else s=3;
		}
		else if(x[2]>=x[1] && x[2]>=x[3]){
			f=2;
			if(x[1]>x[3])s=1;
			else s=3;
		}
		else{
			f=3;
			if(x[1]>x[2])s=1;
			else s=2;
		}
		cnt[f]++;
		q[f][cnt[f]]=x[f]-x[s];
		ans+=x[f];
	}
}a[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		ans=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
			a[i].update();
		}
		if(cnt[1]>(n>>1)){
			sort(q[1]+1,q[1]+cnt[1]+1);
			int j=cnt[1]-(n>>1);
			for(int i=1;i<=j;++i){
				ans-=q[1][i];
			}
		}
		else if(cnt[2]>(n>>1)){
			sort(q[2]+1,q[2]+cnt[2]+1);
			int j=cnt[2]-(n>>1);
			for(int i=1;i<=j;++i){
				ans-=q[2][i];
			}
		}
		else if(cnt[3]>(n>>1)){
			sort(q[3]+1,q[3]+cnt[3]+1);
			int j=cnt[3]-(n>>1);
			for(int i=1;i<=j;++i){
				ans-=q[3][i];
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/