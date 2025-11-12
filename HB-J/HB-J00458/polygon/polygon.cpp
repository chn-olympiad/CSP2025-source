#include<bits/stdc++.h>
using namespace std;

int a[5001];
int vis[5001];
int n;
vector<int> path;
int cu_Max_val;
int sum;
int out;
map<vector<int>,bool> path_vis;

void dfs(int step){
	sort(path.begin(),path.end());
	int re_max_val=cu_Max_val;
	vector<int> re_path=path;
	if(step>=3){
		if(sum>2*cu_Max_val){
			if(path_vis[path]==true) return ;
			out++;
			out%=998244353;
			path_vis[path]=true;
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		path.push_back(i);
		cu_Max_val=max(cu_Max_val,a[i]);
		sum+=a[i];
		vis[i]=true;
		dfs(step+1);
		vis[i]=false;
		sum-=a[i];
		cu_Max_val=re_max_val;
		path=re_path;
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	dfs(0);
	cout << out;
	return 0;
}
