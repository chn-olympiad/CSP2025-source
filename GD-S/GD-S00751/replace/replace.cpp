#include<bits/stdc++.h>

using namespace std;
int n,m;
string s[100010],t[100010],ed;
namespace ACAM{
	int tot=0;
	struct node{
		int ch[26],fail,tag;
		node(){memset(ch,0,sizeof(ch)),fail=tag=0;}
	}; node tree[5000010];
	void _insert(string s,int id){
		int l=s.length(),p=0;
		for(int i=0;i<l;++i){
			int num=s[i]-'a';
			if(!tree[p].ch[num]) tree[p].ch[num]=++tot;
			p=tree[p].ch[num];
		}
		tree[p].tag=id;
	}
	void build(){
		queue<int>q;
		for(int i=0;i<26;++i) if(tree[0].ch[i]) q.push(tree[0].ch[i]);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<26;++i){
				int v=tree[u].ch[i];
				if(v) tree[v].fail=tree[tree[u].fail].ch[i],q.push(v);
				else tree[u].ch[i]=tree[u].fail;
			}
		}
	}
}using namespace ACAM;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i]>>t[i],_insert(s[i],i);
	build();
	while(m--){
	 	string st;cin>>st>>ed;
		int p=0,l=st.length(),ans=0;
		for(int i=0;i<l;++i){
			int num=st[i]-'a';
			p=tree[p].ch[num];
			int q=p;
			while(q) {
				if(tree[q].tag) {
					string  str="";
					int f=tree[q].tag;
					str+=st.substr(0,i-t[f].length()+1);
					str+=t[f];
					str+=st.substr(i+1,l-i);
	//				cout<<st.substr(0,i-t[f].length()+1)<<" "<<t[f]<<" "<<st.substr(i+1,l-i)<<",";
	//				cout<<s[f]<<" "<<st<<"->"<<str<<"\n";
					if(str==ed) ++ans;
				}
				q=tree[q].fail;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
