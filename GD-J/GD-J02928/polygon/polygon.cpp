#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010],n,ans;
map<vector<int>,bool>mp;
void dfs(int cnt,int sum,int ma,vector<int> v){
	if(cnt>=n){
		if(sum>ma*2&&!mp[v])
			ans++,mp[v]=true;
		return;
	}
	if(sum>ma*2&&!mp[v])
		ans++,mp[v]=true;
	vector<int>tmp=v;
	dfs(cnt+1,sum,ma,tmp);
	tmp[cnt]=1;
	dfs(cnt+1,sum+a[cnt+1],max(ma,a[cnt+1]),tmp);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			flag=false;
	}
	if(flag){
		int ans=(n+1)*n/2;
		ans-=n+n-1;
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
	cout<<ans;
	return 0;
}

