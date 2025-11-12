#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;++i)
//#define int unsigned long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define x first
#define y second
const ull P=131,P2=998244353;
const int N=4e5+10;
int n,m;
string s1,s2;
unordered_map<ull,int> mp;
struct node{
	int s[27],fail,ans;
} p;
struct AC{
	vector<node> tr;
	int tot=0;
	void init(){
		tr.push_back(p);
	}
	void insert(string s){
		int u=0;
		for(int i=0;i<s.size();++i){
			int t;
			if(s[i]>='a'&&s[i]<='z') t=s[i]-'a';
			else t=26;
			if(!tr[u].s[t]){
				tr[u].s[t]=++tot;
				init();
			}
			u=tr[u].s[t];
		}
		tr[u].ans++;
	}
	void build(){
		queue<int> q;
		rep(i,0,26) if(tr[0].s[i]) q.push(tr[0].s[i]);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			tr[u].ans+=tr[tr[u].fail].ans;
			rep(i,0,26){
				if(tr[u].s[i]){
					tr[tr[u].s[i]].fail=tr[tr[u].fail].s[i];
					q.push(tr[u].s[i]);
				}
				else tr[u].s[i]=tr[tr[u].fail].s[i];
			}
		}
//		rep(u,1,tot) tr[u].ans+=tr[tr[u].fail].ans;
	}
	int que(string s){
		int ans=0,u=0;
		for(int i=0;i<s.size();++i){
			int t;
			if(s[i]>='a'&&s[i]<='z') t=s[i]-'a';
			else t=26;
			u=tr[u].s[t];
			ans+=tr[u].ans;
		}
		return ans;
	}
} T[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	rep(i,0,26) p.s[i]=0;
	p.fail=p.ans=0;
	int now=0;
	cin>>n>>m;
	rep(i,1,n){
		cin>>s1>>s2;
//		cout<<i<<" "<<s1<<" "<<s2<<"\n";
		string s3="";
		int n=(int)s1.size();
		int p1=0,p2=0;
		rep(i,0,n-1) if(s1[i]!=s2[i]){
			p1=i;
			break;
		}
		for(int i=n-1;i>=0;--i){
			if(s1[i]!=s2[i]){
				p2=i;
				break;
			}
		}
		ull h1=0,h2=0;
		rep(i,p1,p2) h1=h1*P+s1[i],h2=h2*P+s2[i]; 
		if(p1>=1) rep(i,0,p1-1) s3+=s1[i];
		s3+='#';
		rep(i,p2+1,n-1) s3+=s1[i];
		int t=h1*P2+h2;
		if(mp.find(t)!=mp.end()) T[mp[t]].insert(s3);
		else{
			mp[t]=++now;
			T[now].init();
			T[now].insert(s3);
		}
	}
//	return 0;
	rep(i,1,now) T[i].build();
	while(m--){
		string s3="";
		cin>>s1>>s2;
		int n=(int)s1.size(),m=(int)s2.size();
		if(n!=m){
			cout<<0<<"\n";
			continue; 
		}
		int p1=0,p2=0;
		rep(i,0,n-1) if(s1[i]!=s2[i]){
			p1=i;
			break;
		}
		for(int i=n-1;i>=0;--i){
			if(s1[i]!=s2[i]){
				p2=i;
				break;
			}
		}
		if(p1>=1) rep(i,0,p1-1) s3+=s1[i];
		s3+='#';
		rep(i,p2+1,n-1) s3+=s1[i];
//		cout<<s3<<"\n";
		ull h1=0,h2=0,ans=0;
		rep(i,p1,p2) h1=h1*P+s1[i],h2=h2*P+s2[i];
		int t=h1*P2+h2;
		if(mp.find(t)!=mp.end()) cout<<T[mp[t]].que(s3)<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


2 1
b b 
aaaa aaaa
aabaa aabaa
*/
