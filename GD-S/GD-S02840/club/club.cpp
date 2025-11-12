#include<bits/stdc++.h>
using namespace std;
const int ri=1e5+5; 
int T,n,a[ri][5],cnt[5],q[5][ri],ans;
bool cmp(int x,int y){
	return min(a[x][1]-a[x][2],a[x][1]-a[x][3])>min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
bool cmp2(int x,int y){
	return min(a[x][2]-a[x][1],a[x][2]-a[x][3])>min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
}
bool cmp3(int x,int y){
	return min(a[x][3]-a[x][1],a[x][3]-a[x][2])>min(a[y][3]-a[y][1],a[y][3]-a[y][2]);
}
void solve(){
	ans=0;
	memset(cnt,0,sizeof cnt);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int maxn=-1,maxi;
		for(int j=1;j<=3;j++){
			if(a[i][j]>maxn){
				maxn=a[i][j];
				maxi=j;
			}
			if(a[i][j]==maxn&&cnt[j]<cnt[maxi]){
				maxn=a[i][j];
				maxi=j;
			}
		}
		q[maxi][++cnt[maxi]]=i;
		ans+=a[i][maxi];
	}
	if(cnt[1]>n/2){
	    sort(q[1]+1,q[1]+cnt[1]+1,cmp);
	    for(int i=cnt[1];i>=n/2+1;i--){
	    	ans-=min(a[q[1][i]][1]-a[q[1][i]][2],a[q[1][i]][1]-a[q[1][i]][3]);
		}
	}else if(cnt[2]>n/2){
	    sort(q[2]+1,q[2]+cnt[2]+1,cmp2);
	    for(int i=cnt[2];i>=n/2+1;i--){
	    	ans-=min(a[q[2][i]][2]-a[q[2][i]][1],a[q[2][i]][2]-a[q[2][i]][3]);
		}
	}else if(cnt[3]>n/2){
		sort(q[3]+1,q[3]+cnt[3]+1,cmp3);
	    for(int i=cnt[3];i>=n/2+1;i--){
	    	ans-=min(a[q[3][i]][3]-a[q[3][i]][1],a[q[3][i]][3]-a[q[3][i]][2]);
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    	solve();
	}
	return 0;
} 
