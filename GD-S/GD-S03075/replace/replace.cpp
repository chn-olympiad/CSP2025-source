#include<bits/stdc++.h>
using namespace std;
using H=unsigned long long;
const H B=29;
int n,q;
string s,t;
template<class Value>
struct trie{
	struct node{
		Value v;
		node*ch[26];
		node(){v=Value();fill(ch,ch+26,nullptr);}
	}*rt;
	trie(){rt=0;}
	Value&insert(node*&u,const string&s,const int&i){
		if(!u)u=new node;
		if(i==s.size())return u->v;
		return insert(u->ch[s[i]-'a'],s,i+1);
	}Value&insert(const string&s){return insert(rt,s,0);}
};
int find1(const trie<int>&tr,const string&s){
	auto u=tr.rt;
	int ans=0;
	for(const char&c:s){
		if(!u)return ans;
		ans+=u->v;
		u=u->ch[c-'a'];
	}if(u)ans+=u->v;
	return ans;
}int find2(const trie<trie<int>>&tr,const string&s,const string&t){
	auto u=tr.rt;
	int ans=0;
	for(const char&c:s){
		if(!u)return ans;
		ans+=find1(u->v,t);
		u=u->ch[c-'a'];
	}if(u)ans+=find1(u->v,t);
	return ans;
}unordered_map<H,unordered_map<H,trie<trie<int>>>>tr;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(;n--;){
		cin>>s>>t;
		s=' '+s,t=' '+t;
		if(s==t)continue;
		int x=1,y=s.size()-1;
		string a,b;
		for(;x<y&&s[x]==t[x];++x)a+=s[x];
		for(;y>x&&s[y]==t[y];--y)b+=s[y];
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		H c=0,d=0;
		for(int j=x;j<=y;++j)c=c*B+s[j]-'a'+1,d=d*B+t[j]-'a'+1;
		++(((tr[c][d]).insert(a)).insert(b));
	}for(;q--;){
		cin>>s>>t;
		if(s.size()!=t.size()){cout<<"0\n";continue;}
		s=' '+s,t=' '+t;
		int x=1,y=s.size()-1;
		string a,b;
		for(;x<y&&s[x]==t[x];++x)a+=s[x];
		for(;y>x&&s[y]==t[y];--y)b+=s[y];
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		H c=0,d=0;
		for(int j=x;j<=y;++j)c=c*B+s[j]-'a'+1,d=d*B+t[j]-'a'+1;
		cout<<find2(tr[c][d],a,b)<<'\n';
	}
}
/*
I don't know how many points can it get.
The memory may be limit exceeded.
O(L_1+L_2)
忍界第linguistic
仁杰滴linguistic
任杰地linguistic
人界低linguistic
认界第linguistic
忍节滴linguistic
仁姐地linguistic
任借低linguistic
人节第linguistic
认界滴linguistic
忍姐地linguistic
仁借低linguistic
任节第linguistic
人姐滴linguistic
认界地linguistic
忍借低linguistic
仁节第linguistic
……
*/