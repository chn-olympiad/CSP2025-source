#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n;long long ans;
int a[N][3],d[N][3],cnt[3];
priority_queue <array <int,2> > Q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i(1);i<=n;++i){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			d[i][0]=0;d[i][1]=1;d[i][2]=2;
			sort(d[i],d[i]+3,[&](const int &x,const int &y){
				return a[i][x]>a[i][y];
			});
		}
		for(int i(1);i<=n;++i){
			if(cnt[d[i][0]]<(n>>1)){
				++cnt[d[i][0]];
				ans+=a[i][d[i][0]];
				Q[d[i][0]].push({a[i][d[i][1]]-a[i][d[i][0]],i});
			}
			else{
				array <int,2> p(Q[d[i][0]].top());
				if(a[i][d[i][0]]+p[0]>a[i][d[i][1]]){
					Q[d[i][0]].pop();
					Q[d[i][0]].push({a[i][d[i][1]]-a[i][d[i][0]],i});
					ans+=a[i][d[i][0]]+p[0];
				}
				else ans+=a[i][d[i][1]];
			}
		}
		printf("%lld\n",ans);
		ans=0;cnt[0]=cnt[1]=cnt[2]=0;
		while(!Q[0].empty()) Q[0].pop();
		while(!Q[1].empty()) Q[1].pop();
		while(!Q[2].empty()) Q[2].pop();
	}
	return 0;
}
