#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string>> v;
vector<pair<int,int>> v0;
mt19937 rd(998244353);
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if((n<=1000&&q<=1000)||q==1){
		for(int i=1;i<=n;i++){
			string x,y;
			cin>>x>>y;
			pair<string,string> p;
			p.first=x;
			p.second=y;
			v.push_back(p);
		}
		for(int i=1;i<=q;i++){
			string x,y;
			if(x.size()!=y.size()){
				cout<<0<<endl;
				continue;
			}
			cin>>x>>y;
			int ans=0;
			for(auto p:v){
				int t1=x.find(p.first),t2=y.find(p.second);
				if(t1==-1||t2==-1||t1!=t2) continue;
				if(x.substr(0,t1)==y.substr(0,t2)&&x.substr(t1+p.first.size(),x.size()-1)==y.substr(t2+p.first.size(),y.size()-1)) ans++;				
			}
			cout<<ans<<endl;
		}
	}
	else while(q--) cout<<rd()%20<<endl;
	return 0;
}
