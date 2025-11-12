#include <bits/stdc++.h>
#define int long long
using namespace std;

int _T,n,a[100010][5],cnt[5],g[5],ans;

struct node{
	int x,a;
	friend bool operator<(node n1,node n2){
		return n1.a>n2.a;
	}
};
priority_queue<int>q[5];

int find(int x,int j){
	int res=0;
	for(int i=1;i<=3;i++){
		if(i==j)continue;
		res=max(res,a[x][i]);
	}
	return (res-a[x][j]);
}

void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	for(int i=1;i<=n;i++){
		int k=1,maxn=-1e18;
		for(int j=1;j<=3;j++){
			g[j]=a[i][j];
			if(cnt[j]>=n/2){
				g[j]+=q[j].top();
			}
			if(g[j]>maxn){
				maxn=g[j];
				k=j;
			}
//			printf("%lld ",g[j]);
		}
//		printf("-> %lld\n",g[k]);
		if(cnt[k]>=n/2){
			q[k].pop();
			ans+=g[k];
		}else{
			ans+=g[k];
			cnt[k]++;
		}
		q[k].push(find(i,k));
//		printf("%lld %lld %lld  %lld\n",cnt[1],cnt[2],cnt[3],ans);
	}
	printf("%lld\n",ans);
	
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)a[i][j]=0;
	for(int i=1;i<=3;i++){
		g[i]=0;
		cnt[i]=0;
		while(!q[i].empty())q[i].pop();
	}
	ans=0;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%lld",&_T);
	while(_T--)solve();
	
	return 0;
}
