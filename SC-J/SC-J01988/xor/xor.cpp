#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],ans;
vector< pair<int,int> >v;
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first){
		return a.first<b.first;
	}else{
		return a.second<b.second;
	}
}
void dfs(int rr,int xb,int sum){
	for(int i=xb+1;i<v.size();i++){
		if(v[i].first>rr){
			dfs(v[i].second,i,sum+1);
		}
	}
	ans=max(ans,sum);
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			ans+=x;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int xorz=a[i];
		if(xorz==k){
			v.push_back({i,i});
		}
		for(int j=i+1;j<=n;j++){
			xorz^=a[j];
			if(xorz==k){
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		dfs(v[i].second,i,1);
	}
	cout<<ans;
	return 0;
}
