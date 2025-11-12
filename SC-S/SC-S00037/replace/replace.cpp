#include<iostream>
#include<map>

using namespace std;

map<string,string> mapp;
map<string,bool> vis;
map<pair<string,string>,bool> mark;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mapp[s1]=s2;
		vis[s1]=true;
	}
	while(q--){
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size() || (s1.size()==1 && s1!=s2)){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<int(s1.size());i++)
			for(int j=i;j<int(s1.size());j++)
				if(vis[s1] && !mark[{s1.substr(i,j),mapp[s1.substr(i,j)]}] && mapp[s1.substr(i,j)]==s2.substr(i,j))
					cnt++,mark[{s1.substr(i,j),mapp[s1.substr(i,j)]}]=true;
		cout<<cnt<<'\n';
	}
	return 0;
}