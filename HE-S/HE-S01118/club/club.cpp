#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N][4];
int cnt[4];
priority_queue<int>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T;T--){
		cin>>n;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1)q.push(a[i][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=q.top();
			q.pop();
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//int T;
//int n;
//const int N=1e5+10;
//typedef pair<int,int> pai;
//struct node{
//	int id[4];
//	int w[4];
//	
//}p[N];
//priority_queue<pai,vector<pai>,greater<pai> >q[4];
//queue<int>que;
//int ans;
//void dfs(int now){
//	for(int i=1;i<=3;i++){
//		int idx=p[now].id[i],d=p[now].w[i];
//		if(q[idx].size()<n/2){
//			q[idx].push({d,now});
//			ans+=d;
//			return;
//		}
//	}
//	for(int i=1;i<=3;i++){
//		int idx=p[now].id[i],d=p[now].w[i];
//		if(d>q[idx].top().first){
//			ans=ans-q[idx].top().first+d;
//			que.push(q[idx].top().second);
//			q[idx].pop();
//			q[idx].push({d,now});
//		}
//	}
//}
//int main(){
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	for(cin>>T;T;T--){
//		ans=0;
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			int mx=-1,mi=INT_MAX;
//			vector<int>a(5,0);
//			for(int j=1;j<=3;j++){
//				cin>>a[j];
//				if(mx<a[j]){
//					p[i].id[1]=j,mx=a[j];
//				}
//				if(mi>a[j]){
//					p[i].id[3]=j,mi=a[j];
//				}
//			}
//			p[i].id[2]=6-p[i].id[1]-p[i].id[3];
//			p[i].w[1]=mx;
//			p[i].w[2]=a[p[i].id[2]];
//			p[i].w[3]=mi;
//			que.push(i);
//		}
//		while(que.size()){
//			int x=que.front();
//			que.pop();
//			dfs(x);
//		}
//		cout<<ans<<'\n';
//	}
//	return 0;
//}
