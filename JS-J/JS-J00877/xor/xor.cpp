#include<bits/stdc++.h>
using namespace std;
int n,k,ans=-1e9;
vector<int>a;
vector<int>xo;
vector<pair<int,int>>q;
map<int,int>mp;
int dfs(int p){
	if(mp[p])return mp[p];
	else{
		int max1=-1e9;
		for(int i=p+1;i<(int)q.size();i++)if(q[i].first>q[p].second)max1=max(dfs(i)+1,max1);
		mp[p]=max1;
		return max1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a.resize(n+1,0);
	xo.resize(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i],xo[i]=xo[i-1]^a[i];
	for(int i=1;i<=n;i++){
		int want=k^xo[i-1];
		for(int j=i;j<=n;j++)if(xo[j]==want){
			q.push_back(make_pair(i,j));
			break;
		}
	}
	for(int i=0;i<(int)q.size();i++)ans=max(ans,dfs(i)+1);
	cout<<ans+1e9;
	return 0;
}
