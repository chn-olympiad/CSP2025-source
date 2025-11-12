#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
vector<int> a(100);
void dfs(vector<int> q,int len){
	if(len == n+1&&!q.empty()&&len>=3){
		int cnt=0,mex=-1;
		for(int i=0;i<q.size();i++){
			cnt+=q[i];
			mex=max(mex,q[i]);
		}
		if(cnt > mex*2){
			ans+=1;
		}
		return;
	}
	else{
		if(len>n+1){
			return;
		}
		vector<int> q2(q);
		q2.push_back(a[len]);
		dfs(q2,len+1);
		dfs(q,len+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	vector<int> q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(q,1);
	cout<<ans;
}
