#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
const int N=2e5+10,M=5e6+10;
int n,q,cnt=0,tr[M][26];
int len[M*26],nxt[M*26];
int mul[M],slen[N];
ull H1[N],H2[N];
string s1[N],s2[N];
unordered_map<ull,int> mp;

ull Hash_table(int idx,ull Hash){
	ull res=(ull)idx*131+Hash*13131;
	return res;
}

ull get_Hash(string &s){
	ull Hash=0;
	for(int i=0;i<s.size();i++) Hash=Hash*131+s[i]-'a';
	return Hash;
}
void insert(string &s,ull Hash){
	int p=0;
	for(int i=0;i<s.size();i++){
		int c=s[i]-'a';
		if(!tr[p][c]) tr[p][c]=++cnt;
		p=tr[p][c];
	}
	if(!len[p]) len[p]=s.size();
	ull v=Hash_table(p,Hash);
	mp[v]++;
}
void build(){
	queue<int> q;
	for(int i=0;i<26;i++) if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=0;i<26;i++){
			if(tr[x][i]) nxt[tr[x][i]]=tr[nxt[x]][i],q.push(tr[x][i]);
			else tr[x][i]=tr[nxt[x]][i];
		}
	}
}
int calc(int p,int pos,string &t,vector<ull> &Hash2,vector<int> &vis){
	int res=0;
	while(p){
		if(!len[p]){p=nxt[p];}
		ull v=Hash2[pos]-Hash2[pos-len[p]]*mul[len[p]];
		ull H=Hash_table(p,v);
		if(vis[pos-len[p]])res+=mp[H];
		p=nxt[p];
	}
	return res;
}
void solve(string &t1,string &t2){
	if(t1.size()!=t2.size()){
		cout<<0<<endl;
		return ;
	}
	int l=t1.size();
	vector<ull> Hash2(l+5);
	vector<int> vis1(l+5,0),vis2(l+5,0);
	for(int i=1;i<=l;i++) Hash2[i]=Hash2[i-1]*131+t2[i-1]-'a';
	for(int i=1;i<=l;i++){
		if(t1[i-1]!=t2[i-1]) continue;
		vis1[i]=1;
	}
	for(int i=l;i>=1;i--){
		if(t1[i-1]!=t2[i-1]) continue;
		vis2[i]=1;
	}
	vis1[0]=vis2[l+1]=1;
	int p=0,ans=0;
	for(int i=1;i<=l;i++){
		int c=t1[i-1]-'a';
		p=tr[p][c];
		if(vis2[i+1]) ans+=calc(p,i,t2,Hash2,vis1);
	}
	cout<<ans<<endl;
}

namespace BF{
	void solve(string &t1,string &t2){
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			return ;
		}
		int l=t1.size();
		vector<ull> Hash1(l+5,0),Hash2(l+5,0);
		vector<int> vis1(l+5,0),vis2(l+5,0);
		for(int i=1;i<=l;i++)
			Hash1[i]=Hash1[i-1]*131+t1[i-1]-'a',
			Hash2[i]=Hash2[i-1]*131+t2[i-1]-'a';
		for(int i=1;i<=l;i++){
			if(t1[i-1]!=t2[i-1]) break;
			vis1[i]=1; 
		}
		for(int i=l;i>=1;i--){
			if(t1[i-1]!=t2[i-1]) break;
			vis2[i]=1;
		}
		vis1[0]=vis2[l+1]=1;
		int ans=0;
		for(int i=1;i<=l;i++){
			for(int j=1;j<=n;j++){
				if(slen[j]>i) continue;
				ull V1=Hash1[i]-Hash1[i-slen[j]]*mul[slen[j]];
				ull V2=Hash2[i]-Hash2[i-slen[j]]*mul[slen[j]];
				if(V1==H1[j]&&V2==H2[j]&&vis1[i-slen[j]]&&vis2[i+1]) ans++;
			}
		}
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		H1[i]=get_Hash(s1[i]),H2[i]=get_Hash(s2[i]);
		insert(s1[i],H2[i]);
		slen[i]=s1[i].size();
	}
	mul[0]=1;
	for(int i=1;i<=5e6;i++) mul[i]=mul[i-1]*131;
	build();
	for(int i=1;i<=q;i++){
		string t1,t2; cin>>t1>>t2;
//		if(n<=1000&&q<=1000&&t1.size()<=2000){
//			BF::solve(t1,t2); continue;
//		}
//		solve(t1,t2);
		BF::solve(t1,t2);
	}
	return 0;
}