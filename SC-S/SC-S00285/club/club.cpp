#include<bits/stdc++.h>
const int N=1e5+5;
int t,n,ans,a[N][3];
std::priority_queue<int> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int i=1;i<=n;i++){
			int max=std::max(a[i][0],std::max(a[i][1],a[i][2])),id;
			if(a[i][0]==max)id=0;
			if(a[i][1]==max)id=1;
			if(a[i][2]==max)id=2;
			std::sort(a[i],a[i]+3);
			if(q[id].size()==n/2){
				q[id].push(a[i][1]-a[i][2]),ans+=a[i][2];
				ans+=q[id].top(),q[id].pop();
			}
			else{
				ans+=a[i][2];
				q[id].push(a[i][1]-a[i][2]);
			}
		}
		while(!q[0].empty())q[0].pop();
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		printf("%d\n",ans);
	}
}