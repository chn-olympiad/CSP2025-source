#include <bits/stdc++.h>
using namespace std;

struct node{
	int cnt;
	int ch[26*26];
}nnode;
vector<node> t;
int rt,tot;
void insert(string &s1,string &s2){
	int p=rt,len=s1.length();
	for(int i=0;i<len;i++){
		int id=(s1[i]-'a')*26+s2[i]-'a';
		if(!t[p].ch[id]){
			t.push_back(nnode);
			t[p].ch[id]=++tot;	
		}
		p=t[p].ch[id];
		t[p].cnt++;
	}
}
int query(string &s1,string &s2,int l,int r){
	int p=rt,len=s1.length(),res=INT_MAX;
	for(int i=0;i<len;i++){
		int id=(s1[i]-'a')*26+s2[i]-'a';
		if(!t[p].ch[id]){
			t.push_back(nnode);
			t[p].ch[id]=++tot;
		}
		p=t[p].ch[id];
		if(i>=l && i<=r) res=min(res,t[p].cnt);
	}	
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	t.push_back(nnode);
	int n,q;
	cin>>n>>q; 
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		insert(s1,s2);
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.length()!=s2.length()) cout<<0<<'\n';
		else{
			int len=s1.length(),l=-1,r;
			for(int i=0;i<len;i++){
				if(s1[i]!=s2[i]){
					if(l==-1) l=i;
					r=i;
				}
			}
			cout<<query(s1,s2,l,r)<<'\n';			
		}

	}
	return 0;
}
