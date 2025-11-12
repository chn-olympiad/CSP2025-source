#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
int T,n,a[N][3],b[N][3];
struct Node{
	int x,t,fr;
}q[N<<2];
bool vis[N];
bool cmp(Node a,Node b){
	return a.x>b.x;
}
int val[3];
int calc(int x){
	memset(vis,0,sizeof(vis)),memset(val,0,sizeof(val));
	int res=0;
	for(int i=1;i<=n;i++) b[i][0]=a[i][0]-a[i][x],b[i][1]=a[i][1]-a[i][x],b[i][2]=a[i][2]-a[i][x],res+=a[i][x];
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			if(j==x) continue;
			cnt++,q[cnt]={b[i][j],i,j};
		}
	}
	sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(vis[q[i].t]) continue;
		if(val[q[i].fr]>=n/2) continue;
		if(val[0]+val[1]+val[2]>=n/2&&q[i].x<=0) break;
		val[q[i].fr]++,vis[q[i].t]=1,res+=q[i].x;
	}
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
		printf("%lld\n",calc(0));
	}
	return 0;
}
