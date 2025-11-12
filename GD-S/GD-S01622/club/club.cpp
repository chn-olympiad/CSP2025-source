#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,num[5],vis[N],tot,ans=0;
pair<int,int> a[N][5];
struct node{
	int x,id,cl;
	bool operator<(const node &b){
		return x>b.x;
	}
}p[N];
void solve(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q[4];
	tot=0,ans=0;
	memset(num,0,sizeof num);
	memset(vis,0,sizeof vis);
	cin>>n;
	for(int i=1;i<=n;i++){
		pair<int,int> x,y,z;
		x.second=1,y.second=2,z.second=3;
		scanf("%d%d%d",&x.first,&y.first,&z.first);
		if(x<y) swap(x,y);
		if(y<z) swap(y,z);
		if(x<z) swap(x,z);
		if(x<y) swap(x,y);
		if(y<z) swap(y,z);
		if(x<z) swap(x,z);
		a[i][1]=x,a[i][2]=y,a[i][3]=z;
	}
	for(int i=1;i<=n;i++){
		int pid=-1;
		for(int j=1;j<=3;j++){
			vis[i]=j;
			int x=a[i][j].first,id=a[i][j].second;
			if(q[id].size()>=n/2){
				if(x-a[i][j+1].first>q[id].top().first){
					pid=q[id].top().second;
					q[id].pop();
					q[id].push({x-a[i][j+1].first,i});
					ans+=x;
					break;
				}
				else{
					continue;
				}
			}
			else{
				q[id].push({x-a[i][j+1].first,i});
				ans+=x;
				break;
			}
		}
		if(pid==-1) continue;
		ans-=a[pid][vis[pid]].first;
		vis[pid]++;
		q[a[pid][vis[pid]].second].push({a[i][vis[pid]].first-a[i][vis[pid]+1].first,pid});
		ans+=a[pid][vis[pid]].first;
	}
	cout<<ans<<endl;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
} 
