#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int n,q,ans=0;
pair<string,string>p[MAXN];
bool vis[MAXN];
string s1,s2,ls;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		ls=s1;ans=0;
		for(int x=0;x<s1.size();x++){
			for(int i=1;i<=n;i++){
				ls=s1;
				if(vis[i]) continue;
				if(x+p[i].first.size()-1>=ls.size()) continue;
		//		cout<<1;
				if(ls.substr(x,p[i].first.size())==p[i].first){
		//			cout<<ls.substr(x,p[i].first.size())<<"-"<<p[i].first<<" ";
					string ll=ls.substr(x,p[i].first.size());
					for(int j=x;j<x+p[i].first.size();j++){
						ls[j]=p[i].second[j-x];
					}
					if(ls==s2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
 3 4
 a b
 b c
 c d
 aa bb
 aa b
 a c
 b a
*/
