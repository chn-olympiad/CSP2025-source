#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k,sum=0;
	cin>>n>>k;
	unordered_map<int,int>mp;
	vector<pair<int,int>>v;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum^=a;
		if(mp.count(k^sum))
			v.push_back({mp[k^sum]+1,i});
		mp[sum]=i;
	}
	sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
		return a.second<b.second?1:a.second==b.second&&a.first>b.first;
	});
	int lr=0;
	ll ans=0;
	for(auto p:v){
		if(p.first>lr)
			++ans,lr=p.second;
	}
	cout<<ans<<'\n';
	return 0;
}