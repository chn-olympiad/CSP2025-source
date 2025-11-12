#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=2e5+5,M=5e6+5,base=1145141;
unordered_map<ull,int> mp;
int n,q,rt[N],tot=0,cnt=0,ch[M][27],sum[M],fail[M];
void insert(int rt,string s) {
	int u=rt;
	for(int i=0; i<s.size(); i++) {
		if(!ch[u][s[i]-'a']) ch[u][s[i]-'a']=++tot;
		u=ch[u][s[i]-'a'];
	}
	sum[u]++;
}
void build_fail(int rt) {
	queue<int> q;
	for(int i=0; i<27; i++) {
		if(ch[rt][i]) fail[ch[rt][i]]=rt,q.push(ch[rt][i]);
		else ch[rt][i]=rt;
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		sum[u]+=sum[fail[u]];
		for(int i=0; i<27; i++) {
			if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
			else ch[u][i]=ch[fail[u]][i];
		}
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l]) l++;
		if(l==s1.size()) continue;
		while(r>=0&&s1[r]==s2[r]) r--;
		string t="";
		for(int j=0; j<l; j++) t+=s1[j];t+='z'+1;
		for(int j=r+1; j<s1.size(); j++) t+=s1[j];
		ull hsh=0;
		for(int j=l; j<=r; j++) hsh=hsh*base+s1[j];
		for(int j=l; j<=r; j++) hsh=hsh*base+s2[j];
		if(!mp.count(hsh)) rt[++cnt]=++tot,mp[hsh]=rt[cnt];
		insert(mp[hsh],t);
	}
	for(int i=1; i<=cnt; i++) build_fail(rt[i]);
	while(q--) {
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) {cout<<0<<"\n";continue;}
		int l=0,r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l]) l++;
		while(r>=0&&s1[r]==s2[r]) r--;
		string t="";
		for(int j=0; j<l; j++) t+=s1[j];t+='z'+1;
		for(int j=r+1; j<s1.size(); j++) t+=s1[j];
		ull hsh=0;
		for(int j=l; j<=r; j++) hsh=hsh*base+s1[j];
		for(int j=l; j<=r; j++) hsh=hsh*base+s2[j];
		if(!mp.count(hsh)) {cout<<0<<"\n";continue;}
		int u=mp[hsh],ans=0;
		for(int j=0; j<t.size(); j++) {
			u=ch[u][t[j]-'a'];
			ans+=sum[u];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
