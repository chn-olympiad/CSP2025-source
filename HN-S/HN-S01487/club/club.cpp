#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4];
struct node{
	int v,x,w,w2,y;
}b[N];
bool cmp(node a,node b){
	return a.v>b.v;
}
int vis[N],s[N],cnt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int ma=0,ma2=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>ma){
					ma2=ma;
					ma=a[i][j];
					b[i].x=j;
				}
				else{
					if(a[i][j]>ma2){
						ma2=a[i][j];
						b[i].y=j;
					}
				}
			}
			b[i].v=ma-ma2;
			b[i].w=ma;
			b[i].w2=ma2;
		}
		sort(b+1,b+n+1,cmp);
		cnt[1]=cnt[2]=cnt[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[b[i].x]+1<=n/2){
				cnt[b[i].x]++;
				ans=ans+b[i].w;
			}
			else{
				cnt[b[i].y]++;
				ans=ans+b[i].w2;
			}
		}
		printf("%d\n",ans);
	}
//	Èôj>jj
//	ma[j]-ma2[j]>ma[jj]-ma2[jj];
	
	return 0;
}
