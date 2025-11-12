#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][4],mx[N],pmx[N],cnt[4],b[4][N],ans;
bool cmp(int x,int y) {
	return a[x][mx[x]]-a[x][pmx[x]]<a[y][mx[y]]-a[y][pmx[y]];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++) {
			mx[i]=1;
			if(a[i][2]>=a[i][mx[i]]) {
				pmx[i]=mx[i];
				mx[i]=2;
			}
			else pmx[i]=2;
			if(a[i][3]>=a[i][mx[i]]) {
				pmx[i]=mx[i];
				mx[i]=3;
			}
			else if(a[i][3]>=a[i][pmx[i]]) pmx[i]=3;	
		}
		for(int i=1;i<=n;i++) b[mx[i]][++cnt[mx[i]]]=i;
		for(int i=1;i<=3;i++) {
			if(cnt[i]>n/2) {
				sort(b[i]+1,b[i]+cnt[i]+1,cmp);
				for(int j=1;j<=cnt[i]-n/2;j++) ans+=a[b[i][j]][pmx[b[i][j]]];
				for(int j=cnt[i]-n/2+1;j<=cnt[i];j++) ans+=a[b[i][j]][mx[b[i][j]]];
			}
			else {
				for(int j=1;j<=cnt[i];j++) ans+=a[b[i][j]][mx[b[i][j]]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
