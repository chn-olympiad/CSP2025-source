#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans,vis[100005],sum[5],a[100005][3],d[100005];
priority_queue<array<int,3>>q;
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i][2]||a[i][3]){
			return false;
		}
	}
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i][3]){
			return false;
		}
	}
	return true;
}
void solve(){
	vector<int>v;
	for(int i=1;i<=n;i++){
		v.push_back(a[i][1]);
	}
	sort(v.begin(),v.end(),greater<int>());
	int tmp=0;
	for(auto z:v){
		tmp++;
		cout<<z<<' ';
		if(tmp==n/2){
			cout<<'\n';
			return;
		}
	}
}
void dfs(int x){
	if(x>n){
		int A=0,B=0,C=0,sum=0;
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				A++;
			}else if(d[i]==2){
				B++;
			}else{
				C++;
			}
		}
		if(max({A,B,C})>n/2){
			return;
		}
		for(int i=1;i<=n;i++){
			sum+=a[i][d[i]];
		}
		ans=max(ans,sum);
		return;
	}
	d[x]=1;
	dfs(x+1);
	d[x]=2;
	dfs(x+1);
	d[x]=3;
	dfs(x+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>t;t;t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(check()){
			solve();
		}else if(n<=20){
			dfs(1);
			cout<<ans<<'\n';
		}else{
			while(q.size()){
				q.pop();
			}
			fill(vis,vis+n+1,false);
			sum[0]=sum[1]=sum[2]=sum[3]=0;
			for(int i=1;i<=n;i++){
				q.push({a[i][1],i,1});
				q.push({a[i][2],i,2});
				q.push({a[i][3],i,3});
			}
			int tmp=n,ans=0;
			while(tmp){
				auto p=q.top();
				q.pop();
				if(!vis[p[1]]){
					if(sum[p[2]]<n/2){
						sum[p[2]]++;
						vis[p[1]]=true;
						ans+=p[0],tmp--;
					};
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
