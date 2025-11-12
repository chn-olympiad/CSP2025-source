#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][5];
struct node{
	int id,dtmax,maxx,maxid,maxx2,max2id;
};
bool operator <(node x,node y){
	return x.dtmax<y.dtmax;
}
bool operator >(node x,node y){
	return x.dtmax>=y.dtmax;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		priority_queue<node,vector<node>,greater<node> > q[5];
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for(int i=1;i<=n;i++){
			int maxx=0,maxid=0,maxx2=0,max2id=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxx){
					maxx2=maxx,max2id=maxid;
					maxx=a[i][j],maxid=j;
				}
				else if(a[i][j]==maxx)maxx2=maxx,max2id=maxid;
				else if(a[i][j]>maxx2){
					maxx2=a[i][j],max2id=j;
				}
			}
			q[maxid].push({i,maxx-maxx2,maxx,maxid,maxx2,max2id});
			if(q[maxid].size()>n/2){
				node now=q[maxid].top();
				q[maxid].pop();
				q[now.max2id].push({now.id,now.dtmax,now.maxx2,now.max2id,0,0});
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			while(q[i].size()){
				ans+=q[i].top().maxx;
				q[i].pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
