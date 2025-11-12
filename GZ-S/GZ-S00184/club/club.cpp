// GZ-S00184 赫章新纪元学校 彭奥博
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n;
int d[maxn][3],cnt[3];
long long ans=-1e18,t;
void pre(){
	memset(d,0,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	ans=-1e18;
	t=0;
}
void dfs(int idx){
	if(idx==n+1){
		ans=max(ans,t);
		return;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]>=n/2)continue;
		t+=d[idx][i];
		cnt[i]++;
		dfs(idx+1);
		t-=d[idx][i];
		cnt[i]--;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		pre();
		cin>>n;
		for(int i=1;i<=n;i++)cin>>d[i][0]>>d[i][1]>>d[i][2];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
} 
