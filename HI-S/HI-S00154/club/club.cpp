#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int n, a[N][4], b[N][4], c[N];

struct node {
	int i, j;
};

bool operator < (node x, node y) {
	return b[x.i][3]-b[x.i][2]<b[y.i][3]-b[y.i][2];
}

node mknode(int a, int b) {
	node ans;
	ans.i=a;
	ans.j=b;
	return ans;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		priority_queue<node> q[4];
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][1]=a[i][1], b[i][2]=a[i][2], b[i][3]=a[i][3];
			sort(b[i]+1,b[i]+3+1);
			
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				q[1].push(mknode(i,1));
				if(a[i][2]>=a[i][3])c[i]=2;
				else c[i]=3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				q[2].push(mknode(i,2));
				if(a[i][1]>=a[i][3])c[i]=1;
				else c[i]=3;
			}else {
				q[3].push(mknode(i,3));
				if(a[i][1]>=a[i][2])c[i]=1;
				else c[i]=2;
			}
		}
		int ans=0, k=n>>1;
		if(q[1].size()<=k&&q[2].size()<=k&&q[3].size()<=k) {
			while(!q[1].empty()) {
				node t=q[1].top(); q[1].pop();
				ans+=a[t.i][1];
			}
			
			while(!q[2].empty()) {
				node t=q[2].top(); q[2].pop();
				ans+=a[t.i][2];
			}
			
			while(!q[3].empty()) {
				node t=q[3].top(); q[3].pop();
				ans+=a[t.i][3];
			}
		}else if(q[1].size()>k) {
			for(int i=1;i<=k;i++) {
				node t=q[1].top(); q[1].pop();
				ans+=a[t.i][1];
			}
			while(!q[1].empty()) {
				node t=q[1].top(); q[1].pop();
				q[c[t.i]].push(mknode(t.i, c[t.i]));
			}
			
			while(!q[2].empty()) {
				node t=q[2].top(); q[2].pop();
				ans+=a[t.i][2];
			}
			
			while(!q[3].empty()) {
				node t=q[3].top(); q[3].pop();
				ans+=a[t.i][3];
			}
		}else if(q[2].size()>k) {
			for(int i=1;i<=k;i++) {
				node t=q[2].top(); q[2].pop();
				ans+=a[t.i][2];
			}
			while(!q[2].empty()) {
				node t=q[2].top(); q[2].pop();
				q[c[t.i]].push(mknode(t.i, c[t.i]));
			}
			
			while(!q[1].empty()) {
				node t=q[1].top(); q[1].pop();
				ans+=a[t.i][1];
			}
			
			while(!q[3].empty()) {
				node t=q[3].top(); q[3].pop();
				ans+=a[t.i][3];
			}
		} else{
			for(int i=1;i<=k;i++) {
				node t=q[3].top(); q[3].pop();
				ans+=a[t.i][3];
			}
			while(!q[3].empty()) {
				node t=q[3].top(); q[3].pop();
				q[c[t.i]].push(mknode(t.i, c[t.i]));
			}
			while(!q[2].empty()) {
				node t=q[2].top(); q[2].pop();
				ans+=a[t.i][2];
			}
			
			while(!q[1].empty()) {
				node t=q[1].top(); q[1].pop();
				ans+=a[t.i][1];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
