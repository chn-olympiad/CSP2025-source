#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,M=4,inf=1e9+10;
int a[N][M],sl[M],zd[N];
priority_queue<int,vector<int>,greater<int>>q[M];
int gt(int x){
	if(zd[x])return zd[x];
	int p=max(max(a[x][1],a[x][2]),a[x][3]);
	for(int i=1;i<=3;i++)if(a[x][i]==p)return zd[x]=i;
}
int jj(int x){
	int ans=inf;
	for(int i=1;i<=3;i++)if(i!=gt(x))ans=min(ans,a[x][gt(x)]-a[x][i]);
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%lld",&t);
	while(t--){
		int n;scanf("%lld",&n);
		for(int i=1;i<=3;i++)while(q[i].size())q[i].pop();
		memset(sl,0,sizeof(sl));memset(zd,0,sizeof(zd));
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)scanf("%lld",&a[i][j]);
		for(int i=1;i<=n;i++)sl[gt(i)]++;
		int ans=0;for(int i=1;i<=n;i++)ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		for(int i=1;i<=n;i++)q[gt(i)].push(jj(i));
		for(int i=1;i<=3;i++){
			while(sl[i]>n/2){
				ans-=q[i].top();
				q[i].pop(); 
				sl[i]--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
