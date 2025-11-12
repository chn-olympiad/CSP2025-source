#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=10000000000000061ll,bas=127;
int n,q,is[200005],it[200005],cnt,tot[2],siz[400005],tr[400005],dfn[400005],id[2][400005][26],ans[200005];
string s[200005][2],t[200005][2];
ll hs[200005],ht[200005];
vector<int> to[2][400005],tg[400005];
vector<array<int,2>> qr[400005];
vector<string> ts[2][400005];
bool cmps(int x,int y){
	return hs[x]<hs[y];
}
bool cmpt(int x,int y){
	return ht[x]<ht[y];
}
int ist(int op,string &s){
	int p=0,nw=0;
	while(nw<s.size()){
		int &I=id[op][p][s[nw]-'a'];
		if(I==-1){
			string w="";
			for(int i=nw;i<s.size();i++) w+=s[i];
			to[op][p].push_back(++tot[op]);
			ts[op][p].push_back(w),I=ts[op][p].size()-1;
			return tot[op];
		}
		else{
			int lcp=0;
			for(int i=0;nw+i<s.size()&&i<ts[op][p][I].size();i++)
				if(s[nw+i]==ts[op][p][I][i]) lcp++;
				else break;
			if(nw+lcp==s.size()&&lcp==ts[op][p][I].size()) return to[op][p][I];
			if(lcp==ts[op][p][I].size()) nw+=lcp,p=to[op][p][I];
			else{
				tot[op]++;
				string w="";
				while(ts[op][p][I].size()>lcp) w+=ts[op][p][I].back(),ts[op][p][I].pop_back();
				reverse(w.begin(),w.end());
				int tmp=to[op][p][I];
				to[op][p][I]=tot[op],to[op][tot[op]]={tmp},ts[op][tot[op]]={w},id[op][tot[op]][w[0]-'a']=0;
				p=tot[op],nw+=lcp;
			}
		}
	}
	return p;
}
int gt(int op,string &s){
	int p=0,nw=0;
	while(nw<s.size()){
		int &I=id[op][p][s[nw]-'a'];
		if(I==-1) return p;
		else{
			int lcp=0;
			for(int i=0;nw+i<s.size()&&i<ts[op][p][I].size();i++)
				if(s[nw+i]==ts[op][p][I][i]) lcp++;
				else break;
			if(lcp==ts[op][p][I].size()) nw+=lcp,p=to[op][p][I];
			else return p;
		}
	}
	return p;
}
void add(int x){ 
	int px=ist(0,s[x][0]),py=ist(1,s[x][1]);
	tg[px].push_back(py);
}
void dfs(int x){
	dfn[x]=++cnt,siz[x]=1;
	for(int v:to[1][x])
		dfs(v),siz[x]+=siz[v];
}
void solve(int x){
	int xd=gt(0,t[x][0]),yd=gt(1,t[x][1]);
//	cout<<xd<<' '<<yd<<'\n';
	qr[xd].push_back({x,yd});
}
void Add(int x,int y){
	for(;x<=tot[1]+1;x+=x&-x) tr[x]+=y;
}
int qry(int x){
	int res=0;
	for(;x;x&=x-1) res+=tr[x];
	return res;
}
void dfs2(int x){
	for(int v:tg[x]) Add(dfn[v],1),Add(dfn[v]+siz[v],-1);
	for(auto v:qr[x])
		ans[v[0]]=qry(dfn[v[1]]);
	for(int v:to[0][x]) dfs2(v);
	for(int v:tg[x]) Add(dfn[v],-1),Add(dfn[v]+siz[v],1); 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1],is[i]=i;
		int lcp=0,lcs=0;
		while(lcp<s[i][0].size()&&s[i][0][lcp]==s[i][1][lcp]) lcp++;
		while(lcs<s[i][0].size()&&s[i][0][s[i][0].size()-lcs-1]==s[i][1][s[i][0].size()-lcs-1]) lcs++;
		if(lcp==s[i][0].size()) hs[i]=-1;
		else{
			for(int j=lcp;j+lcs<s[i][0].size();j++) hs[i]=(hs[i]*bas+s[i][0][j])%mod;
			for(int j=lcp;j+lcs<s[i][0].size();j++) hs[i]=(hs[i]*bas+s[i][1][j])%mod;
			s[i][0]=s[i][0].substr(0,lcp),reverse(s[i][0].begin(),s[i][0].end());
			s[i][1]=s[i][1].substr(s[i][1].size()-lcs,lcs);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1],it[i]=i;
		if(t[i][0].size()!=t[i][1].size()){
			ht[i]=-1;
			continue;
		}
		int lcp=0,lcs=0;
		while(lcp<t[i][0].size()&&t[i][0][lcp]==t[i][1][lcp]) lcp++;
		while(lcs<t[i][0].size()&&t[i][0][t[i][0].size()-lcs-1]==t[i][1][t[i][0].size()-lcs-1]) lcs++;
		for(int j=lcp;j+lcs<t[i][0].size();j++) ht[i]=(ht[i]*bas+t[i][0][j])%mod;
		for(int j=lcp;j+lcs<t[i][0].size();j++) ht[i]=(ht[i]*bas+t[i][1][j])%mod;
		t[i][0]=t[i][0].substr(0,lcp),reverse(t[i][0].begin(),t[i][0].end());
		t[i][1]=t[i][1].substr(t[i][1].size()-lcs,lcs);
	}
	sort(is+1,is+n+1,cmps),sort(it+1,it+q+1,cmpt);
	memset(id,-1,sizeof(id));
	for(int i=1,j=0;i<=n;i++){
		int x=is[i];
		add(x);
		if(i==n||hs[is[i+1]]!=hs[x]){
			cnt=0,dfs(0);
			while(j<q&&ht[it[j+1]]<=hs[x]){
				j++;
				if(ht[it[j]]==hs[x])
					solve(it[j]);
			}
			dfs2(0);
			for(int j=0;j<=tot[0]+1;j++) qr[j].clear(),tg[j].clear();
			for(int j=0;j<=tot[1]+1;j++) tr[j]=0;
			for(int tt=0;tt<2;tt++)
				for(int j=0;j<=tot[tt];j++){
					to[tt][j].clear(),ts[tt][j].clear();
					for(int k=0;k<26;k++) id[tt][j][k]=-1;
				}
			tot[0]=tot[1]=0;
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
