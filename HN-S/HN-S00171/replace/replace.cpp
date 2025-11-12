#include<bits/stdc++.h>
using namespace std;
const int64_t base=71,mod=2893210409849827;
int n,q,ans[200005],mpid,lps[200005],lpt[200005],rps[200005],rpt[200005],preid[200005],sufid[200005];
string s1[200005],s2[200005],t1[200005],t2[200005];
vector<int>vs[200005],vt[200005];
map<pair<int64_t,int64_t>,int>mp;
struct node{
	int p,l,r,val;
	node(int p,int l,int r,int val):p(p),l(l),r(r),val(val){}
	friend bool operator<(node x,node y){
		if(x.p==y.p)
			return x.val<y.val;
		return x.p<y.p;
	}
};
vector<node>vec;
struct tree{
	int tot,dfntot,dfn[5000005],low[5000005],t[5000005][26];
	void clear(){
		for(int i=1;i<=tot;i++)
			for(int j=0;j<26;j++)
				t[i][j]=0;
		tot=1,dfntot=0;
	}
	int emplace(string&s){
		int cur=1;
		for(char ch:s){
			int x=ch-'a';
			if(!t[cur][x])
				t[cur][x]=++tot;
			cur=t[cur][x];
		}
		return cur;
	}
	void dfs(int cur){
		dfn[cur]=++dfntot;
		for(int i=0;i<26;i++)
			if(t[cur][i])
				dfs(t[cur][i]);
		low[cur]=dfntot;
	}
	int query(string&s){
		int cur=1;
		for(char ch:s){
			int x=ch-'a';
			if(!t[cur][x])
				break;
			cur=t[cur][x];
		}
		return cur;
	}
}prt,sft;
namespace fenwick{
	int t[5000005],lim;
	void reset(int _lim){
		fill(t+1,t+lim+1,0),lim=_lim;
	}
	void update(int x,int y){
		for(;x<=lim;x+=x&-x)
			t[x]+=y;
	}
	int query(int x){
		int ret=0;
		for(;x;x-=x&-x)
			ret+=t[x];
		return ret;
	}
	void update(int l,int r,int val){
		update(l,val),update(r+1,-val);
	}
}
pair<int,int>find(string&s1,string&s2){
	int m=s1.size()-1,lp=0,rp=0;
	for(int i=1;i<=m;i++)
		if(s1[i]!=s2[i]){
			if(!lp)
				lp=i;
			rp=i;
		}
	return {lp,rp};
}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cin>>n>>q;
	for(int i=1,id;i<=n;i++){
		cin>>s1[i]>>s2[i],s1[i]='#'+s1[i],s2[i]='#'+s2[i];
		auto [lp,rp]=find(s1[i],s2[i]);
		lps[i]=lp,rps[i]=rp;
		if(!lp)
			continue;
		int64_t hsh1=0,hsh2=0;
		for(int j=lp;j<=rp;j++)
			hsh1=(hsh1*base+(s1[i][j]-'a'+1))%mod,
			hsh2=(hsh2*base+(s2[i][j]-'a'+1))%mod;
		pair<int64_t,int64_t>tmp={hsh1,hsh2};
		if(!mp.count(tmp))
			mp[tmp]=++mpid;
		id=mp[tmp],vs[id].emplace_back(i);
	}
	for(int i=1,id;i<=q;i++){
		cin>>t1[i]>>t2[i],t1[i]='#'+t1[i],t2[i]='#'+t2[i];
		if(t1[i].size()!=t2[i].size())
			continue;
		auto [lp,rp]=find(t1[i],t2[i]);
		lpt[i]=lp,rpt[i]=rp,assert(lp);
		int64_t hsh1=0,hsh2=0;
		for(int j=lp;j<=rp;j++)
			hsh1=(hsh1*base+(t1[i][j]-'a'+1))%mod,
			hsh2=(hsh2*base+(t2[i][j]-'a'+1))%mod;
		if(!mp.count({hsh1,hsh2}))
			continue;
		id=mp[{hsh1,hsh2}],vt[id].emplace_back(i);
	}
	for(int o=1;o<=mpid;o++)
		if(!vt[o].empty()){
			prt.clear(),sft.clear(),vec.clear();
			for(int i:vs[o]){
				string pre=s1[i].substr(1,lps[i]-1),suf=s1[i].substr(rps[i]+1);
				reverse(pre.begin(),pre.end()),preid[i]=prt.emplace(pre),sufid[i]=sft.emplace(suf);
			}
			prt.dfs(1),sft.dfs(1);
			for(int i:vs[o])
				vec.emplace_back(prt.dfn[preid[i]],sft.dfn[sufid[i]],sft.low[sufid[i]],1),
				vec.emplace_back(prt.low[preid[i]]+1,sft.dfn[sufid[i]],sft.low[sufid[i]],-1);
			for(int i:vt[o]){
				string pre=t1[i].substr(1,lpt[i]-1),suf=t1[i].substr(rpt[i]+1);
				reverse(pre.begin(),pre.end());
				int preidt=prt.query(pre),sufidt=sft.query(suf);
				vec.emplace_back(prt.dfn[preidt],sft.dfn[sufidt],i,2);
			}
			sort(vec.begin(),vec.end()),fenwick::reset(sft.tot);
			for(node x:vec){
				if(x.val!=2)
					fenwick::update(x.l,x.r,x.val);
				else
					ans[x.r]=fenwick::query(x.l);
			}
		}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}