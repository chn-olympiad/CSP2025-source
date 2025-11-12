/*by lz*//*ccf明年出简单一点吧*//*35*/
#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+5;
int n;
int cnt=0;//有几个边
struct node {
	int u,v,w;
} a[NN*3+5];
bool vis[NN];
int club[5],ans=0;
bool cmp(node A,node B) {
	return A.w>B.w;
}
void init() {
	ans=0;
	for(int i=1; i<=n; i++) {
		vis[i]=false;
	}
	for(int i=1; i<=3; i++) {
		club[i]=0;
	}
}
void solve() {
	init();
	sort(a+1,a+cnt+1,cmp);
	for(int i=1; i<=cnt; i++) {
		int men=a[i].u,to=a[i].v,interst=a[i].w;
		if(vis[men]==false) {
			if(club[to]+1<=n/2) {
				//加入该集团
				ans+=interst;
				club[to]++;
				vis[men]=true;
			} else if(club[to]>n/2){
				//跳过；
				continue;
			}
		} else if(vis[men]==true){ //该人已经访问过了
			continue;
		}
	}
//	cout<<"答案:" ;
	cout<<ans<<"\n";
//	cout<<"club:";
//	for(int i=1;i<=n;i++){
//		cout<<club[i]<<' ';
//	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cnt=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			int op1,op2,op3;
			cin>>op1>>op2>>op3;
			a[++cnt].u=i,a[cnt].v=1,a[cnt].w=op1;
			a[++cnt].u=i,a[cnt].v=2,a[cnt].w=op2;
			a[++cnt].u=i,a[cnt].v=3,a[cnt].w=op3;
		}
		solve();/**/
//		for(int i=1; i<=cnt; i++) {
//			cout<<"人:"<<a[i].u<<" "<<"集团:"<<a[i].v<<" "<<"兴趣:"<<a[i].w<<"\n";
//		}
//		cout<<"\n\n";
	}

	return 0;
}

