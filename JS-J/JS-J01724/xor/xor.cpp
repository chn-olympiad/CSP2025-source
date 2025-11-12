#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],c[500005],d[500005],fl[500005],r,tot;
vector<int> v[500005];
vector<pair<int,int>> fn;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//input here
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],c[i]=c[i-1]^a[i],v[c[i]].push_back(i);
	//main body here
	for(int i=0;i<=n;i++){
		auto x=upper_bound(v[c[i]^k].begin(),v[c[i]^k].end(),i);
		if(x==v[c[i]^k].end()) continue;
		if(!fl[*x]||fl[*x]<i) fl[*x]=i;
	}
	for(int i=0;i<=n;i++) if(fl[i]||(c[i]==k&&i!=0)) fn.push_back(make_pair(fl[i]+1,i));
	for(auto x:fn) {
//		cout<<x.first<<' '<<x.second<<endl;
		if(x.first>r) r=x.second,tot++;
	}
	//output here
	cout<<tot;
}
