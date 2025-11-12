//replace
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
namespace _746969_{
	int n,q,a[30],b[30],len,ans,ps,t,last;
	pair<pair<string,string>,int> s[200010];
	string x,y;
	bool f,vis[200010];
	signed main(){
		cin>>n>>q;
		for(int i=1;i<=n;i++)
			cin>>s[i].first.first>>s[i].first.second,s[i].second=s[i].first.first.size();
		while(q--){
		// for(int ttt=1;ttt<=q;ttt++){
			cin>>x>>y;
			// if(ttt==18353){
			// 	cout<<x<<" "<<y<<"\n";
			// 	return 0;
			// }
			if(x.size()!=y.size()){
				cout<<0;
				goto flag;
			}
			memset(a,ans=0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(vis,0,sizeof(vis));
			len=x.size();
			for(int i=0;i<len;i++){
				++a[x[i]-'a'+1];
				++b[y[i]-'a'+1];
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<s[i].second;j++){
					--a[s[i].first.first[j]-'a'+1];
					++a[s[i].first.second[j]-'a'+1];
				}
				f=1;
				for(int i=1;i<=26;i++)
					if(a[i]!=b[i]){
						f=0;
						break;
					}
				if(f){
					++ans;
					vis[i]=1;
				}
				for(int j=0;j<s[i].second;j++){
					++a[s[i].first.first[j]-'a'+1];
					--a[s[i].first.second[j]-'a'+1];
				}
			}
			if(!ans){
				cout<<0;
				goto flag;
			}
			ans=0;
			for(int i=1;i<=n;i++){
				if(!vis[i])
					continue;
				last=ps=0;
				while((t=x.find(s[i].first.first,ps))+1){
					if(x.substr(last,t)!=y.substr(last,t))
						break;
					if(y.substr(t,s[i].second)==s[i].first.second)
						++ans;
					ps=t+1;
				}
			}
			cout<<ans;
			flag:
			cout<<"\n";
		}
		return 0;
	}
};
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return _746969_::main();
}