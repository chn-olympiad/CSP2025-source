#include<bits/stdc++.h>
using namespace std;
int t,n,ans,f[100005],g[100005],a[5][100005],ans1,ans2;
priority_queue<pair<int,int> >q,pq,p;
priority_queue<int>pc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		} 
		for(int i=1;i<=n;i++){
			p.push({a[1][i],i});
		}
		for(int i=1;i<=n/2;i++){
			ans+=p.top().first;
			f[p.top().second]=1;
			p.pop();
		}
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				q.push({a[2][i],i});
			}
			else{
				pq.push({a[2][i]-a[1][i],i});
			}
		}
		for(int i=1;i<=n/2;i++){
			while(q.size()&&(g[q.top().second]==1||f[q.top().second]==1)){
				q.pop();
			}
			while(p.size()&&(g[p.top().second]==1||f[p.top().second]==1)){
				p.pop();
			}
			int a1=q.top().first,a2=pq.top().first+p.top().first;
			if(a1>=a2){
				ans+=a1;
				g[q.top().second]=1;
				q.pop();
			}
			else{
				ans+=a2;
				int a3=a[2][p.top().second]-a[1][p.top().second],a4=p.top().second;
				f[p.top().second]=1;
				g[pq.top().second]=1;
				f[pq.top().second]=0;
				p.pop();
				pq.pop();
				pq.push({a3,a4});
			}
		}
		for(int i=1;i<=n;i++){
			if(f[i]&&a[3][i]-a[1][i]>0){
				pc.push(a[3][i]-a[1][i]);
			}
			if(g[i]&&a[3][i]-a[2][i]>0){
				pc.push(a[3][i]-a[2][i]);
			}
		}
		int cnt=0;
		while(pc.size()&&cnt<n/2){
			ans+=pc.top();
			cnt++;
			pc.pop();
		}
		while(pc.size()){
			pc.pop();
		}
		while(q.size()){
			q.pop();
		}
		while(p.size()){
			p.pop();
		}
		while(pq.size()){
			pq.pop();
		}
		cout<<ans<<"\n";
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		ans=0;
	}
	return 0;
} 