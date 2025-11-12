#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int b1=37,mod1=15000017,b2=41,mod2=998244853;
pair<int,int> getHsh(const string &s,int l,int r){
	int ret1=0,ret2=0;
	for(int i=l;i<=r;i++){
		ret1=(1ll*ret1*b1+s[i]-'a'+1)%mod1;
		ret2=(1ll*ret2*b2+s[i]-'a'+1)%mod2;
	}
	return {ret1,ret2};
}
int son1[5000005][26],rt[5000005],tot1=0,tot2=0;
int getRt(int p,string s,int l,int r){
	for(int i=l;i<=r;i++){
		int &son=son1[p][s[i]-'a'];
		if(!son) son=++tot1;
		p=son;
	}
	if(!rt[p]) rt[p]=++tot2;
	return rt[p];
}
int son2[5000005][26],ct[5000005];
void ins(int p,string s,int l,int r){
	for(int i=l;i<=r;i++){
		int &son=son2[p][s[i]-'a'];
		if(!son) son=++tot2;
		p=son;
	}
	ct[p]++;
}
vector<pair<string,int> > qry[5000005];
int ans[1000000];
void work(int p){
	// if(rt[p]) dfs(rt[p],1);
	// for(auto it:qry[p])
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<pair<pair<int,int>,pair<int,int> >,int> root;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		int m=s.size(),lp=-1,rp=-1;
		for(int j=0;j<m;j++){
			if(s[i]!=t[i]){
				lp=i;
				break;
			}
		}
		for(int j=m-1;j>=0;j--){
			if(s[i]!=t[i]){
				rp=i;
				break;
			}
		}
		if(lp==-1) continue;
		pair<int,int> d1=getHsh(s,lp,rp),d2=getHsh(t,lp,rp);
		if(!root[{d1,d2}]) root[{d1,d2}]=++tot1;
		int p=root[{d1,d2}];
		p=getRt(p,s,0,lp-1);
		ins(p,s,rp+1,m-1);
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()) continue;
		int m=s.size(),lp=-1,rp=-1;
		for(int j=0;j<m;j++){
			if(s[i]!=t[i]){
				lp=i;
				break;
			}
		}
		for(int j=m-1;j>=0;j--){
			if(s[i]!=t[i]){
				rp=i;
				break;
			}
		}
		if(lp==-1) continue;
		pair<int,int> d1=getHsh(s,lp,rp),d2=getHsh(t,lp,rp);
		string ss="";
		for(int j=rp+1;j<m;j++) ss.push_back(s[j]);
		if(!root.count({d1,d2})) continue;
		int p=root[{d1,d2}];
		p=getRt(p,s,0,lp-1);
		qry[p].push_back({ss,i});
	}
	for(auto it:root) work(it.second);
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
/*
好想吐，不想写了。
我是怎么打出这么唐的发挥的？真的好难受，
真的打不动竞赛了。
不知道有没有人能看到。
*/