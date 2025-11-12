#include<bits/stdc++.h>
using namespace std;
#define int long long
const int big_o=29,mod_o=(1<<50)-1,big_s=31,mod_s=(1<<51)-1;
int n,q,cfo[5000005],cfs[5000005],pres[5000005];
string a[200005],b[200005];
pair<int,int>ranges[200005];
pair<pair<pair<int,int>,pair<int,int> >,int>l[200005];
pair<int,int> hashs(string x){
	int o=0,s=0;
	for(int i=0;i<x.length();i++) o=o*big_o+x[i]-'0',o%=mod_o,s=s*big_s+x[i]-'0',s%=mod_s;
	return {o,s};
}
pair<int,int>ft(int l,pair<int,int>s){
	return {s.first/cfo[l],s.second/cfs[l+1]};
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cfo[0]=cfs[0]=1;
	for(int i=1;i<5000005;i++) cfo[i]=cfo[i-1]*big_o%mod_o,cfs[i]=cfs[i-1]*big_s%mod_s;
	for(int i=1;i<=n;(a[i]==b[i]?n--,i--:i++)) cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		ranges[i]={2e9,0};
		for(int j=0;j<a[i].length();j++) if(a[i][j]!=b[i][j]) ranges[i].first=min(ranges[i].first,j),ranges[i].second=max(ranges[i].second,j);
		l[i]={{hashs(a[i].substr(ranges[i].first,ranges[i].second-ranges[i].first+1)),hashs(b[i].substr(ranges[i].first,ranges[i].second-ranges[i].first+1))},i};
		pres[i]=ranges[i].first-1;
	}
	sort(l+1,l+1+n);
	while(q--){
		string x,y;
		int ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++) if()
		cout<<ans<<"\n";
	}
	return 0;
}
