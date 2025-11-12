#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
int head[10020];
int a[10020];
int dis[10020];
bool bo[1010020];
int sum;
struct Node {
	int to,ans,next;
} e[1010020];
void egg(int u,int v,int t) {
	sum++;
	e[sum].to=v;
	e[sum].ans=t;
	e[sum].next=head[u];
	head[u]=sum;
}
int bfs() {
	queue<int>q;
	q.push(1);
	dis[1]=0;
	while(!q.empty()) {
		int no=q.front();
//		cout<<no<<endl;
		q.pop();
		for(int i=head[no]; i; i=e[i].next) {
			int t=e[i].ans;
			int v=e[i].to;
			
			if(!bo[i]) {

				if(a[v]==0) {
					ans+=t;
					a[v]=t;
				} else if(a[v]>t) {
					ans-=a[v];
					a[v]=t;
//					dis[v]=dis[no]+t;
					ans+=a[v];
				}
				if(i%2==0) {
					bo[i]=true;
					bo[i-1]=true;
				} else {
					bo[i]=true;
					bo[i+1]=true;
				}
				q.push(v);
			}else if(a[v]>t) {
				ans-=a[v];
				a[v]=t;
//					dis[v]=dis[no]+t;
				ans+=a[v];
			}
		}
	}
	return ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		egg(t1,t2,t3);
		egg(t2,t1,t3);
	}
	memset(dis,0x3f,sizeof(dis));
	cout<<bfs();
	return 0;
}
//6 6 0
//2 1 1
//1 3 2
//3 5 3
//6 2 4
//4 2 5
//2 5 6
