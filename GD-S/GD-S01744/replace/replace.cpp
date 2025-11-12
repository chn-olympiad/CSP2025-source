#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int L=5e6,C=26;
int n,q,t[L+50][C],fail[L+50],m,cnt,ti[L+50];
unordered_map<ull,int> mp[L+50],MP;
char c1[L],c2[L];
ull erro(){
	const ull P1=29,MOD1=1e9+7, P2=31,MOD2=1e9+9;
	m=1;
	while(c1[m+1]) ++m; 
	ull _s1=0,s1=0,_s2=0,s2=0;
	for(int i=m;i;--i){
		s1=s1*P1%MOD1;
		s2=s2*P2%MOD2; 
		if(c1[i]!=c2[i]){
			(s1+=(c1[i]-'a')*C+(c2[i]-'a'+1))%=MOD1;
			(s2+=(c1[i]-'a')*C+(c2[i]-'a'+1))%=MOD2;
			_s1=s1,_s2=s2;
		}
	}
	return _s1<<32|_s2;
}
queue<int> Q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>(c1+1)>>(c2+1);
		ull e=erro();MP[e]=1;
//		cout<<e<<"\n";
		int p=0;
		for(int i=1;i<=m;++i){
			int &to=t[p][c1[i]-'a'];
			if(to==0) to=++cnt;
			p=to;
		}
		++mp[p][e];
	}
	for(int i=0;i<C;++i) if(t[0][i]) Q.push(t[0][i]);
	while(Q.size()){
		int p=Q.front();Q.pop();
		for(int i=0;i<C;++i){
			int &to=t[p][i];
			if(to) fail[to]=t[fail[p]][i],Q.push(to);
			else to=t[fail[p]][i];
		}
//		for(auto i:mp[fail[p]]){
//			auto I=mp[p].find(i.first);
//			if(I==mp[p].end()) mp[p].insert(i);
//			else I->second+=i.second;
//		}
	}
//	cout<<"------------\n";
	for(int T=1;T<=q;++T){
		cin>>(c1+1)>>(c2+1);
		ull e=erro();
		if(MP.count(e)==0){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1,p=0;i<=m;++i){
			p=t[p][c1[i]-'a'];
			for(int x=p;x&&ti[x]!=T;x=fail[x]){
				ti[x]=T;
				auto I=mp[x].find(e);
				if(I!=mp[x].end()) ans+=I->second;
			}
		}
		cout<<ans<<'\n';
	}
}

