#include<bits/stdc++.h>
using namespace std;
long long t,n,x[100007][10],ans=0,sx=0,sy=0,sz=0;
double a[100007][10];
map<int,bool> mp;
priority_queue<pair<double,long long> > q;
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mp.clear();
		sx=0;
		sy=0;
		sz=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i][1]>>x[i][2]>>x[i][3];
			a[i][1]=1.0*x[i][1]/(x[i][1]+x[i][2]+x[i][3]);
			a[i][2]=1.0*x[i][2]/(x[i][1]+x[i][2]+x[i][3]);
			a[i][3]=1.0*x[i][3]/(x[i][1]+x[i][2]+x[i][3]);
		}
		for(int i=1;i<=n;i++){
			q.push({a[i][1],i});
		}
		while(!q.empty()&&(q.top().first<a[q.top().second][2]||q.top().first<a[q.top().second][3])){
			q.pop();
		}
		while(sx<n/2&&q.size()>0){//cout<<"1"<<endl;
			int cnt=0;
			mp[q.top().second]=1;
			sx++;
			ans+=x[q.top().second][1];
			q.pop();
			while(!q.empty()&&(q.top().first<a[q.top().second][2]||q.top().first<a[q.top().second][3])){
				q.pop();
			}
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(mp[i]==1) continue;
			q.push({a[i][2],i});
		}
		while(!q.empty()&&(q.top().first<a[q.top().second][3])){
			q.pop();
		}
		while(sy<n/2&&q.size()>0){//cout<<"2"<<endl;
			int cnt=0;
			mp[q.top().second]=1;
			sy++;
			ans+=x[q.top().second][2];
			q.pop();
			while(!q.empty()&&(q.top().first<a[q.top().second][3])){
				q.pop();
			}
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(mp[i]==1) continue;
			q.push({a[i][3],i});
		}
		while(!q.empty()&&(q.top().first<a[q.top().second][1])){
			q.pop();
		}
		while(sz<n/2&&q.size()>0){//cout<<"3"<<endl;
			int cnt=0;
			mp[q.top().second]=1;
			sz++;
			ans+=x[q.top().second][3];
			q.pop();
			while(!q.empty()&&(q.top().first<a[q.top().second][1])){
				q.pop();
			}
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(sx+sy+sz==n) break;
			if(mp[i]==1) continue;
			if(sx<n/2&&sy<n/2&&sz<n/2){
				int ma=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][1]==ma){
					sx++;
					ans+=x[i][1];
				}
				else if(a[i][2]==ma){
					sy++;
					ans+=x[i][2];
				}
				else{
					sz++;
					ans+=x[i][3];
				}
			}
			else if(sx<n/2&&sy<n/2){
				int ma=max(a[i][1],a[i][2]);
				if(a[i][1]==ma){
					sx++;
					ans+=x[i][1];
				}
				else{
					sy++;
					ans+=x[i][2];
				}
			}
			if(sx<n/2&&sz<n/2){
				int ma=max(a[i][1],a[i][3]);
				if(a[i][1]==ma){
					sx++;
					ans+=x[i][1];
				}
				else{
					sz++;
					ans+=x[i][3];
				}
			}
			if(sy<n/2&&sz<n/2){
				int ma=max(a[i][2],a[i][3]);
				if(a[i][2]==ma){
					sy++;
					ans+=x[i][2];
				}
				else{
					sz++;
					ans+=x[i][3];
				}
			}
			else if(sx<n/2){
				sx++;
				ans+=x[i][1];
			}
			else if(sy<n/2){
				sy++;
				ans+=x[i][2];
			}
			else if(sz<n/2){
				sz++;
				ans+=x[i][3];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
