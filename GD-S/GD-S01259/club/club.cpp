#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n;
struct people{
	int num[4],first,second,third;
}a[N];
struct visit{
	bool inqueue=false;
	bool q_pop[4]={false};
}vis[N];
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].first=a[i].second=a[i].third=0;
			vis[i].inqueue=false;
			for(int j=1;j<=3;j++){
				a[i].num[j]=0;
				vis[i].q_pop[j]=false;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].num[j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].num[1]>=a[i].num[2]&&a[i].num[1]>=a[i].num[3]){
				a[i].first=1;
				if(a[i].num[2]>=a[i].num[3]){
					a[i].second=2;
					a[i].third=3;
				}else{
					a[i].second=3;
					a[i].third=2;
				}
			}else if(a[i].num[2]>=a[i].num[1]&&a[i].num[2]>=a[i].num[3]){
				a[i].first=2;
				if(a[i].num[1]>=a[i].num[3]){
					a[i].second=1;
					a[i].third=3;
				}else{
					a[i].second=3;
					a[i].third=1;
				}
			}else if(a[i].num[3]>=a[i].num[1]&&a[i].num[3]>=a[i].num[2]){
				a[i].first=3;
				if(a[i].num[1]>=a[i].num[2]){
					a[i].second=1;
					a[i].third=2;
				}else{
					a[i].second=2;
					a[i].third=1;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i].first<<" "<<a[i].second<<" "<<a[i].third<<endl;
//		}
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q[4];
		for(int i=1;;){
			if(vis[i].inqueue) continue;
			int x=a[i].first,y=a[i].second,z=a[i].third;
//			cout<<vis[i].q_pop[x]<<endl;
			if(!vis[i].inqueue&&!vis[i].q_pop[x]){
				int num=a[i].num[x];
				if(q[x].size()>=n/2){
					if(num>q[x].top().first){
						vis[q[x].top().second].q_pop[x]=true;
						vis[q[x].top().second].inqueue=false;
						q[x].pop();
						q[x].push({num,i});
						vis[i].inqueue=true;
					}
				}else{
					q[x].push({num,i});
					vis[i].inqueue=true;
				}
			}
			if(!vis[i].inqueue&&!vis[i].q_pop[y]){
				int num=a[i].num[y];
				if(q[y].size()>=n/2){
					if(num>q[y].top().first){
						vis[q[y].top().second].q_pop[y]=true;
						vis[q[y].top().second].inqueue=false;
						q[y].pop();
						q[y].push({num,i});
						vis[i].inqueue=true;
					}
				}else{
					q[y].push({num,i});
					vis[i].inqueue=true;
				}
			}
			if(!vis[i].inqueue&&!vis[i].q_pop[z]){
				int num=a[i].num[z];
				if(q[z].size()>=n/2){
					if(num>q[z].top().first){
						vis[q[z].top().second].q_pop[z]=true;
						vis[q[z].top().second].inqueue=false;
						q[z].pop();
						q[z].push({num,i});
						vis[i].inqueue=true;
					}
				}else{
					q[z].push({num,i});
					vis[i].inqueue=true;
				}
			}
//			if(q[1].size()) cout<<1<<" "<<q[1].size()<<" "<<q[1].top().second<<" "<<endl;
//			if(q[2].size()) cout<<2<<" "<<q[2].size()<<" "<<q[2].top().second<<" "<<endl;
//			if(q[3].size()) cout<<3<<" "<<q[3].size()<<" "<<q[3].top().second<<" "<<endl;
//			cout<<q[1].size()+q[2].size()+q[3].size()<<endl;
			if(q[1].size()+q[2].size()+q[3].size()==n) break;
			if((i+1)%n==0) i=n;
			else if(i==n) i=1;
			else i++;
//			cout<<i<<endl;
		}
		while(q[1].size()){
			ans+=q[1].top().first;
			q[1].pop();
		}
		while(q[2].size()){
			ans+=q[2].top().first;
			q[2].pop();
		}
		while(q[3].size()){
			ans+=q[3].top().first;
			q[3].pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1 2 10 9 8 4 0 0
