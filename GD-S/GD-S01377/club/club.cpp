#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node {int x,y,z;} a[N];
struct node1 {
	int x,y,z;
	bool operator < (const node1 &b) const {
		return -x+max(y,z)<-b.x+max(b.y,b.z);
	}
};
struct node2 {
	int x,y,z;
	bool operator < (const node2 &b) const {
		return -y+max(x,z)<-b.y+max(b.x,b.z);
	}
};
struct node3 {
	int x,y,z;
	bool operator < (const node3 &b) const {
		return -z+max(x,y)<-b.z+max(b.x,b.y);
	}
};
priority_queue<node1> q1;
priority_queue<node2> q2;
priority_queue<node3> q3;
int n,T;
node To_n1(node1 t) {return (node){t.x,t.y,t.z};}
node To_n2(node2 t) {return (node){t.x,t.y,t.z};}
node To_n3(node3 t) {return (node){t.x,t.y,t.z};}
node1 To_1(node t)  {return (node1){t.x,t.y,t.z};}
node2 To_2(node t)  {return (node2){t.x,t.y,t.z};}
node3 To_3(node t)  {return (node3){t.x,t.y,t.z};}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++) {
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) q1.push(To_1(a[i]));
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) q2.push(To_2(a[i]));
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) q3.push(To_3(a[i]));
			while(q1.size()>n/2) {
				node t=To_n1(q1.top());
				if(t.y>t.z) q2.push(To_2(t));
				else        q3.push(To_3(t));
				q1.pop();
			}
			while(q2.size()>n/2) {
				node t=To_n2(q2.top());
				if(t.x>t.z) q1.push(To_1(t));
				else        q3.push(To_3(t));
				q2.pop();
			}
			while(q3.size()>n/2) {
				node t=To_n3(q3.top());
				if(t.x>t.y) q1.push(To_1(t));
				else        q2.push(To_2(t));
				q3.pop();
			}
		}
		int ans=0;
		while(!q1.empty()) ans+=q1.top().x,q1.pop();
		while(!q2.empty()) ans+=q2.top().y,q2.pop();
		while(!q3.empty()) ans+=q3.top().z,q3.pop();
		cout<<ans<<'\n';
	}
} 
