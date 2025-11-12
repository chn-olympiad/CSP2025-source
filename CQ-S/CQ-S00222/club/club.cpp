#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+5;
int n;
int a[N][3];
int cnt[3];
void sol(){
	cnt[0]=cnt[1]=cnt[2]=0;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	ll ans=0;
	priority_queue<int,vector<int>,greater<int>>q[3];
	for(int i=1;i<=n;i++){
		int maxn=max({a[i][0],a[i][1],a[i][2]}),id=0;
		ans+=maxn;
		for(int j=0;j<3;j++)if(a[i][j]==maxn){
			id=j;
			break;
		}
		cnt[id]++;
		sort(a[i],a[i]+3);
		q[id].push(maxn-a[i][1]);
	}
	int maxn=max({cnt[0],cnt[1],cnt[2]});
	if(maxn>n/2){
		for(int i=0;i<3;i++)if(cnt[i]==maxn){
			while(cnt[i]>n/2){
				ans-=q[i].top();
				q[i].pop();
				cnt[i]--;
			}
			break;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)sol();
	return 0;
}
