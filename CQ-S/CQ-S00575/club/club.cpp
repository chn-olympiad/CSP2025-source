#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn][10],b[maxn],ans,vis[maxn],cnt[maxn];
void solve(){ 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	//priority
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >q1,q2,q3;
	for(int i=1;i<=n;i++){
		int g1=a[i][1],g2=a[i][2],g3=a[i][3];
		if(q1.size()+1>n/2){
			int x=q1.top().first,y=q1.top().second;
			int c1=a[i][2],c2=a[i][3];
			if(q2.size()+1>n/2){
				
			}
		}
	}
	cout<<ans<<endl;
}
void dfs(int i){
	if(i==n+1){
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			return ;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][vis[i]];
		}
		ans=max(ans,sum);
		return;
	} 
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
		return ;
	}
	vis[i]=1;
	cnt[1]++;
	dfs(i+1);
	cnt[1]--;
	vis[i]=0;
	vis[i]=2;
	cnt[2]++;
	dfs(i+1);
	vis[i]=0;
	cnt[2]--;
	cnt[3]++;
	vis[i]=3;
	dfs(i+1);
	vis[i]=0;
	cnt[3]--; 
}
void solve1(){ 
	ans=0; 
	dfs(1);
	cout<<ans<<endl;
} 
void solve2(){
	priority_queue<int>q;
	for(int i=1;i<=n;i++){
		q.push(a[i][1]);
	}
	int ans=0,cnt=0;
	while(!q.empty()){
		ans+=q.top();
		q.pop();
		cnt++;
		if(cnt==n/2)break;
	} 
	cout<<ans;
}
void solve3(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1,q2;
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){
			if(q1.size()<n/2){
				q1.push({a[i][1],i}); 
			}else{
				int u=q1.top().first,v=q1.top().second;
				int x1=a[i][1]-(a[v][1]-a[v][2]);
				int x2=a[i][2];
				if(x1>=x2){
					q1.pop();
					q2.push({a[v][2],v});
					q1.push({a[i][1],i});
				}else{
					q2.push({a[i][2],i});
				}
			}
		}else{
			if(q2.size()<n/2){
				q2.push({a[i][2],i}); 
			}else{
				int u=q2.top().first,v=q2.top().second;
				int x1=a[i][2]-(a[v][2]-a[v][1]);
				int x2=a[i][1];
				if(x1>=x2){
					q2.pop();
					q1.push({a[v][1],v});
					q2.push({a[i][2],i});
				}else{
					q1.push({a[i][1],i});
				}
			}
		}
	}
	int ans=0;
	while(!q1.empty()){
		ans+=a[q1.top().second][1];
		q1.pop();
	}
	while(!q2.empty()){
		ans+=a[q2.top().second][2];
		q2.pop();
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){ 
		cin>>n;
		bool flagA=1,flagB=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				flagA=0;
			}
			if(a[i][3]!=0){
				flagB=0;
			}
		}
		if(n<=30)solve1();
		else if(flagA){
			solve2();
		}else if(flagB){
			solve3();
		}
		//solve();
	}
	return 0;
}
/*
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
*/
