#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][5];
struct Node {
	int p1,p2,v;
} p[N];
struct Queue {
	int val,id;
	bool operator < (const Queue &x) const {
		return val>x.val;
	}
};
int cnt[5];
priority_queue<Queue> q[5];
inline void init_() {
	for(int i=1;i<=3;i++)
		cnt[i]=0;
	return ;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		init_(); 
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
			p[i].p1=p[i].p2=0; 
		}
		for(int i=1;i<=n;i++) {
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) p[i].p1=1;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) p[i].p1=2;
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) p[i].p1=3;
			for(int j=1;j<=3;j++) {
				if(j==p[i].p1)
					continue;
				if(a[i][j]>=a[i][p[i].p2])
					p[i].p2=j;
			}
			p[i].v=a[i][p[i].p1]-a[i][p[i].p2];
			Queue tmp=(Queue){p[i].v,i};
			q[p[i].p1].push(tmp);
			cnt[p[i].p1]++;
		}
		for(int i=1;i<=3;i++) {
			while(cnt[i]>n/2) {
				Queue tmp=q[i].top();
				q[i].pop();
				q[p[tmp.id].p2].push(tmp);
				cnt[p[tmp.id].p2]++;
				cnt[i]--;
			}
		}
		int ans=0; 
		while(!q[1].empty()) {
			Queue t=q[1].top();
			q[1].pop();
			ans+=a[t.id][1];
		}
		while(!q[2].empty()) {
			Queue t=q[2].top();
			q[2].pop();
			ans+=a[t.id][2];
		}
		while(!q[3].empty()) {
			Queue t=q[3].top();
			q[3].pop();
			ans+=a[t.id][3];
		}
		printf("%d\n",ans);
	}
	return 0;
}
