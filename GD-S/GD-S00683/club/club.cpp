#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,ans;
pair<int,int>a[5];
priority_queue<int,vector<int>,greater<int>>q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=0;i<3;i++)
			while(!q[i].empty()) q[i].pop();
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				scanf("%d",&a[j].first),
				a[j].second=j;
			sort(a,a+3);
			int id=a[2].second,v=a[2].first-a[1].first;
			if(q[id].size()<(n>>1))
				q[id].push(v),
				ans+=a[2].first;
			else if(q[id].top()<v)
				ans-=q[id].top(),q[id].pop(),
				q[id].push(v),ans+=a[2].first;
			else q[a[1].second].push(a[1].first-a[0].first),ans+=a[1].first;
		}
		printf("%d\n",ans);
	}
	return 0;
}
