#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
long long n,cnt;
int a[5050];
vector<int> path;
map<vector<int>,int> mp;
int mpow(int k){
	int res=1;
	for(int i=1;i<=k;i++){
		res=(res*2)%p;
	}
	return res;
}
void dfs(int id,int sum,int maxl){\
	if(mp.count(path)) return;
	if(maxl*2<sum){
		mp[path]=1;
		cnt=(cnt+1)%p;
	}
	if(id==n+1) return; 
	path.push_back(id);
	dfs(id+1,sum+a[id],max(maxl,a[id]));
	path.pop_back();
	dfs(id+1,sum,maxl);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		cnt=mpow(n)-1-n-(n*(n-1)/2);
	}else{
		dfs(1,0,0);
	}
	cout<<cnt;
	return 0;
}
