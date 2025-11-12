#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
struct node{
	int id,cnt;
	pair<int,int> a[3];
}v[N];
priority_queue<node> q[3];
int t,n,cnt[3],ans;
bool operator <(node a,node b){
	return a.a[a.cnt].first-a.a[a.cnt+1].first>b.a[b.cnt].first-b.a[b.cnt+1].first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		ans=0;
		fill(cnt,cnt+3,0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i].a[0].first>>v[i].a[1].first>>v[i].a[2].first;
			v[i].a[0].second=0; v[i].a[1].second=1; v[i].a[2].second=2;
			v[i].cnt=0;
			v[i].id=i;
			if(v[i].a[0]<v[i].a[1]) swap(v[i].a[0],v[i].a[1]);
			if(v[i].a[1]<v[i].a[2]) swap(v[i].a[1],v[i].a[2]);
			if(v[i].a[0]<v[i].a[1]) swap(v[i].a[0],v[i].a[1]);
		}
		for(int i=1;i<=n;i++){
			ans+=v[i].a[v[i].cnt].first;
			if(cnt[v[i].a[v[i].cnt].second]<n/2){
				int vvv=v[i].a[v[i].cnt].second;
				q[vvv].push(v[i]);
				cnt[vvv]++;
			}
			else{
				int vvv=v[i].a[v[i].cnt].second;
				node x=q[vvv].top(); q[vvv].pop();
				if(x<v[i]){
					ans-=v[i].a[v[i].cnt].first-v[i].a[v[i].cnt+1].first;
					v[i].cnt++;
				}
				else{
					ans-=x.a[x.cnt].first-x.a[x.cnt+1].first;
					x.cnt++;
				}
				if(x.cnt!=2) q[x.a[x.cnt].second].push(x);
				if(v[i].cnt!=2) q[v[i].a[v[i].cnt].second].push(v[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
