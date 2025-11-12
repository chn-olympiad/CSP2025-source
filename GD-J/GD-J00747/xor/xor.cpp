#include<bits/stdc++.h>
using namespace std;
int n,a[500010],s[500010],k,vis=-1,ans;
map<int,vector<int> >mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	mp[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		mp[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		auto pl=upper_bound(mp[s[i]^k].begin(),mp[s[i]^k].end(),vis);
		if(pl==mp[s[i]^k].end())continue;
		if(*pl<i)ans++,vis=i-1;
	}
	cout<<ans;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
}
