#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N][4],out[N];
vector<int>club[4];
bool cmp(int x,int y){
	return max(a[x][1],max(a[x][2],a[x][3]))<max(a[y][1],max(a[y][2],a[y][3]));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--){
		int ans=0;
		for(int i=1;i<=n;i++) club[i].clear();
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		int num[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			int id=1,mx=a[i][1];
			for(int j=2;j<=3;j++) if(mx<a[i][j]||(mx==a[i][j]&&num[id]>num[j])) id=j,mx=a[i][j];
			club[id].push_back(i),num[id]++,ans+=mx;
		}
		int id=0;
		for(int i=1;i<=3;i++) if(num[i]>(n/2)) id=i;
		if(id==0){
			printf("%lld\n",ans);
			continue; 
		}
		out[0]=0;
		for(int i=0;i<club[id].size();i++){
			int xb=club[id][i];
			sort(a[xb]+1,a[xb]+4);
			out[++out[0]]=a[xb][3]-a[xb][2];
		}
		sort(out+1,out+1+out[0]);
		for(int i=1;i<=(out[0]-(n/2));i++) ans-=out[i];
		printf("%lld\n",ans);
	}
	return 0;
} 
