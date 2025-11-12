//GZ-S00384 贵阳市清华中学 胡钦焯 
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n,t,ans=-1,place[5],sum[N][5];
void dfs(int ren/*现在是第几个*/,int sam/*当前值*/,int T/*容量*/,int nn) {
	if(ren==nn) {
		if(sam>ans) ans=sam;
		return ;
	}
	for(int i=1; i<=3; i++) {
		if(place[i]<T) {
			ren+=1;
			place[i]+=1;
			sam+=sum[ren][i];
			dfs(ren,sam,T,nn);
			sam-=sum[ren][i];
			ren--;
			place[i]--;
			
		}
	}
	return ;
}
int main() {
	freopen("club.input","r",stdin);
	freopen("club.output","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>n;
		int T=n/2;
		for(int j=1; j<=n; j++) cin>>sum[j][1]>>sum[j][2]>>sum[j][3];
		dfs(0,0,T,n);
		cout<<ans<<endl;
		ans=-1;
		memset(place,0,sizeof(place));
		memset(sum,0,sizeof(sum));
	}
	return 0;
}
