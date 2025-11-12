#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,bool>tag;
string x,y;
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>x>>y,tag[make_pair(x,y)]=1;
	while(q--) {
		cin>>x>>y;
		int l=0x3f3f3f3f,r=0,ans=0;
		if(x.size()!=y.size()) {
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<x.size();i++)if(x[i]!=y[i])l=min(l,i),r=max(r,i);
		for(int i=l;i>=0;i--) {
			string t="",s="";
			for(int j=i;j<r;j++)t+=x[j],s+=y[j];
			for(int j=r;j<x.size();j++) {
				t+=x[j],s+=y[j];
				if(tag[make_pair(t,s)])ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

