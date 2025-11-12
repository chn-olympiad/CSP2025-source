#include<bits/stdc++.h>
using namespace std;
int xo(vector<int>a){
	int re=1;
	for(int i=0;i<a.size();i++){
		re=(re xor a[i]);
	}
	return re;
}
int k,ans=0;vector<bool>vis;vector<int>a;
void dfs(vector<vector<int>>now,int xb,int are){
	if(xo(now[are])==k){
		vector<int>c;
		now.push_back(c);
		are++;
		ans=max(are,ans);
		for(int i=xb+1;i<a.size();i++){
			if(!vis[i]){
				now[are].push_back(a[i]);
				vis[i]=1;
				dfs(now,i,are);
				vis[i]=0;
				now[are].pop_back();
			}
		}
	}
	else if(!vis[xb+1]&&(a.size()-now[are].size()-1)>ans){
		now[are].push_back(a[xb+1]);
		vis[xb+1]=1;
		dfs(now,xb+1,are);
		vis[xb+1]=0;
		now[are].pop_back();
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n>>k;
	a.push_back(0);
	vis.push_back(0);
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		a.push_back(c);
		vis.push_back(0); 
	}
	vector<vector<int>> now;
	vector<int>c;
	now.push_back(c);
	dfs(now,0,0);
	cout<<ans;
	return 0;
} 
//这题本来有更好方法剪枝的，时间不够了 
