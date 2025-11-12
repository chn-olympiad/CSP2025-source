#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,q;
vector<pair<string,string>> vec;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	// ast len=bst len
	for(int i=1;i<=n;i++){
		string ast,bst;cin>>ast>>bst;
		vec.push_back({ast,bst});
	}
	for(int i=1;i<=q;i++){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
		}
		int res=0;
		for(auto p:vec){
			if(p.first.size()>s.size())continue;
			auto sp=s.find_first_of(p.first),tp=t.find_first_of(p.second);
			auto sp2=s.find_first_of(p.first,sp+p.first.size()),tp2=t.find_first_of(p.second,sp+p.second.size());
			if(sp!=-1&&tp!=-1&&sp==tp&&sp2==-1&&tp2==-1)res++; 
		}
		cout<<res<<"\n";
	}
	return 0;
} 
