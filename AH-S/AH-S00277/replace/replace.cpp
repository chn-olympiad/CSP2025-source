#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD1;
const int INF=1e18;
const int N=200005;
const int base=13;
int n,q;
pii w[N];
int id[N];
int gethash(string s){
	int res=0;
	for(int i=0;i<s.size();i++){
		res=(res*base%MOD+(s[i]-'a'+1))%MOD;
	}
	return res%MOD;
}
struct Trie{
	int tr[N][30];
	int tot=0;
	int tot2=0;
	int dfn[N];
	int L[N],R[N];
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<=26;j++){
				tr[i][j]=0;
			}
			dfn[i]=L[i]=R[i]=0;
		}
		tot=tot2=0;
	}
	int insert(string s){
		//Trie insert
		int p=0;
		for(int i=0;i<s.size();i++){
			if(!tr[p][s[i]-'a']){
				tr[p][s[i]-'a']=++tot;
			}
			p=tr[p][s[i]-'a'];
		}
		return p;
	}
	void dfs(int u){
		L[u]=R[u]=dfn[u]=++tot2;
		for(int i=0;i<=26;i++){
			if(tr[u][i]){
				dfs(tr[u][i]);
				L[u]=min(L[u],L[tr[u][i]]);
				R[u]=max(R[u],R[tr[u][i]]);
			}
		}
	}
	int find(string s){
		int p=0;
		for(int i=0;i<s.size();i++){
			if(!tr[p][s[i]-'a']){
				return -1;
			}
			p=tr[p][s[i]-'a'];
		}
		return p;
	}
	
}T1,T2;
int ans[N];
struct Query{
	int id2;
	pair<string,string> s;
	int w1,w2;
};
struct segtree{
	int tr[4*N],tag[4*N];
	void pushup(int p){
		tr[p]=tr[p*2]+tr[p*2+1];
	}
	void pushdown(int p,int l,int r){
		if(tag[p]){
			tag[p*2]+=tag[p];
			tag[p*2+1]+=tag[p];
			int mid=(l+r)/2;
			tr[p*2]+=(mid-l+1)*tag[p];
			tr[p*2+1]+=(r-mid)*tag[p];
			tag[p]=0;
		}
	}
	void modify(int p,int l,int r,int L,int R,int x){
		if(l>=L&&r<=R){
			tr[p]+=(r-l+1)*x;
			tag[p]+=x;
			return;
		}
		pushdown(p,l,r);
		int mid=(l+r)/2;
		if(mid>=L)modify(p*2,l,mid,L,R,x);
		if(mid<R)modify(p*2+1,mid+1,r,L,R,x);
		pushup(p);
	}
	int query(int p,int l,int r,int x){
		if(l==r){
			return tr[p];
		}
		pushdown(p,l,r);
		int mid=(l+r)/2;
		if(mid>=x)return query(p*2,l,mid,x);
		else return query(p*2+1,mid+1,r,x);
	}
}T3;
vector<Query> vec[N];
vector<pair<string,string>> vec2[N];
vector<pii> vec3[N];//x y id
struct op{
	int l,r,w;
};
vector<op> vec4[N];
//int w1[N],w2[N];
void solve(int t){
	//cout<<t<<"\n";
	T1.clear();
	T2.clear();
	for(int i=0;i<vec[t].size();i++){
		string tmp=vec[t][i].s.fi;
		reverse(ALL(tmp));
		vec[t][i].w1=T1.insert(tmp);
		vec[t][i].w2=T2.insert(vec[t][i].s.se);
		//cout<<vec[t][i].s.fi<<" "<<vec[t][i].s.se<<"\n";
		//cout<<vec[t][i].w1<<" "<<vec[t][i].w2<<"\n";
	}
	T1.dfs(0);
	T2.dfs(0);
	for(int i=0;i<vec[t].size();i++){
		vec3[T1.dfn[vec[t][i].w1]].push_back({T2.dfn[vec[t][i].w2]
			,vec[t][i].id2});
	}
	int mx=0;
	for(int i=0;i<vec2[t].size();i++){
		string tmp=vec2[t][i].fi;
		reverse(ALL(tmp));
		int x=T1.find(tmp);
		int y=T2.find(vec2[t][i].se);
		//cout<<"vec2: "<<vec2[t][i].fi<<" "<<vec2[t][i].se<<"\n";
		//cout<<"vec2: "<<T1.L[T1.dfn[x]]<<" "<<T1.R[T1.dfn[x]]<<"\n";
		//cout<<"vec2: "<<T1.L[x]<<" "<<T1.R[x]<<"\n";
		//cout<<"vec2: "<<T2.L[y]<<" "<<T2.R[y]<<"\n";
		if(x==-1||y==-1)continue;
		vec4[T1.L[x]].push_back({T2.L[y],T2.R[y],1});
		vec4[T1.R[x]+1].push_back({T2.L[y],T2.R[y],-1});
		mx=max(mx,T1.R[x]+1);
	}
	int mx2=T2.tot2+1;
	for(int i=0;i<=mx;i++){
		for(auto [l,r,w]:vec4[i]){
			//cout<<i<<" "<<l<<" "<<r<<" "<<w<<"\n";
			T3.modify(1,1,mx2,l,r,w);
		}
		for(auto [x,y]:vec3[i]){
			ans[y]=T3.query(1,1,mx2,x);
		}
	}
	for(int i=0;i<vec[t].size();i++){
		vec3[vec[t][i].w1].clear();
	}
	for(int i=0;i<=mx;i++){
		vec4[i].clear();
	}
}
void solve_(){
	cin>>n>>q;
	map<pii,int> mp;
	int tot=0;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		string tmp1,tmp2,tmp3,tmp4;
		int pos1=0,pos2=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				pos1=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				pos2=j;
				break;
			}
		}
		for(int j=pos1;j<=pos2;j++){
			tmp1+=s1[j];
			tmp2+=s2[j];
		}
		
		for(int j=0;j<pos1;j++){
			tmp3+=s1[j];
		}
		for(int j=pos2+1;j<s1.size();j++){
			tmp4+=s1[j];
		}
		w[i]={gethash(tmp1),gethash(tmp2)};
		if(!mp.count(w[i])){
			mp[w[i]]=++tot;
		}
		id[i]=mp[w[i]];
		vec2[id[i]].push_back({tmp3,tmp4});
		//cout<<w[i].fi<<" "<<w[i].se<<"\n";
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		string tmp1,tmp2,tmp3,tmp4;
		int pos1=0,pos2=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				pos1=j;
				break;
			}
		}
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				pos2=j;
				break;
			}
		}
		for(int j=pos1;j<=pos2;j++){
			tmp1+=t1[j];
			tmp2+=t2[j];
		}
		for(int j=0;j<pos1;j++){
			tmp3+=t1[j];
		}
		for(int j=pos2+1;j<t1.size();j++){
			tmp4+=t1[j];
		}
		pii tmp={gethash(tmp1),gethash(tmp2)};
		if(!mp.count(tmp)){
			ans[i]=0;
		}else{
			vec[mp[tmp]].push_back({i,make_pair(tmp3,tmp4)});
		}
		//cout<<gethash(tmp1)<<" "<<gethash(tmp2)<<"\n";
	}
	//solve(1);
	for(int i=1;i<=tot;i++){
		solve(i);
		//for(auto [s1,s2]:vec[i]){
		//	cout<<i<<" "<<s1<<" "<<s2<<"\n";
		//}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase=1,multitest=0;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
