#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,val;
};
vector<node> mp[10005];
int c[20][10005],sum,res,ans=1e9;
bool v[10005],flag=0;
vector<int> lu;
void dfs(int x){
	if (res==0){
		ans=min(ans,sum);
		return;
	}
	for (node i:mp[x]){
		if (!v[i.d]){
			sum+=i.val;
			res--;
			v[i.d]=1;
			lu.push_back(i.d);
			dfs(i.d);
			lu.pop_back();
			sum-=i.val;
			v[i.d]=0;
			res++;
		}
	}
	if (!flag){
		flag=1;
		for (int i:lu){
			dfs(i);
		}
		flag=0;
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		mp[x].push_back({y,z});
		mp[y].push_back({x,z});
	}
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	res=n-1;
	v[1]=1;
	dfs(1);
	cout<<ans;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
