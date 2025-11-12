#include<bits/stdc++.h>
using namespace std;
#define lbt(i) (i&(-i))
#define ll long long
#define __int __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define psb push_back
#define lbd lower_bound
#define pbd upper_bound
#define endl '\n'

const int mx=1e4+5;
int n,m;
map<pair<string,string>,int>c;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x;
		if(x=="\n") cin>>x;
		cin>>y;
		if(y==" ") cin>>y;
		c[{x,y}]++;
	}
	while(m--){
		string x,y;
		cin>>x;
		if(x=="\n") cin>>x;
		cin>>y;
		if(y==" ") cin>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		int l=x.size(),r=0,ans=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				l=min(i,l);
				r=max(i,r);
			}
		}
		for(int i=l;i>=0;i--){
			pair<string,string> cr={"",""};
			for(int j=i;j<r;j++) cr.F+=x[j],cr.S+=y[j];
			for(int j=r;j<x.size();j++){
				cr.F+=x[j];
				cr.S+=y[j];
				ans+=c[cr];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
