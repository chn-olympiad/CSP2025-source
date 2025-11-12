#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
int vis_club[4];
int a[N][4];
int ans;
int dfs(int x,int w){
	if(x>=n)return w;
	int nans=0;
	for(int i=1;i<=3;i++){
		if(vis_club[i]<n/2){
			vis_club[i]++;
			nans=max(nans,dfs(x+1,w+a[x+1][i]));
			vis_club[i]--;
	 }
	}
	return nans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(vis_club,0,sizeof vis_club);
		memset(a,0,sizeof a);
		cin>>n;
		for(int i=1;i<=n;i++){
			int i1,i2,i3;
			scanf("%d",&i1);
			scanf("%d",&i2);
			scanf("%d",&i3);
			a[i][1]=i1,a[i][2]=i2,a[i][3]=i3;
		}
		for(int i=1;i<=3;i++){
			vis_club[i]++;
			ans=max(ans,dfs(1,a[1][i]));
			vis_club[i]--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
