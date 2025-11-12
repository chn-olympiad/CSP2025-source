#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,base=233;
int n,q;
int ans[N];
string s[N][2],t[N][2];
int p1[N],p2[N],l1[N],r1[N],l2[N],r2[N];
ull h1[N],h2[N];
const int M=5e6+N;
int nx[M][27],w[M];
vector<int>g1[M],g2[M];
int id[N];
int np;
ull p[N<<1];
int len=1;
vector<int>e1[N<<1],e2[N<<1];
void dfs(int u){
	for(int i:g1[u]){
		w[id[i]]++;
	}
	for(int i:g2[u]){
		int p=1;
		ans[i]=w[p];
		for(int j=r2[i]+1;j<t[i][0].size();j++){
			int c=t[i][0][j]-'a';
			p=nx[p][c];
			ans[i]+=w[p];
			if(!p)break;
		}
	}
	for(int i=0;i<26;i++){
		if(nx[u][i])dfs(nx[u][i]);
	}
	for(int i:g1[u]){
		w[id[i]]--;
	}
}
void cle(){
	for(int i=0;i<=np;i++){
		g1[i].clear(),g2[i].clear();w[i]=0;
		for(int j=0;j<26;j++)nx[i][j]=0;
	}
	np=1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)p1[i]=i;
	for(int i=1;i<=q;i++)p2[i]=i;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		if(s[i][0].size()!=s[i][1].size())continue;
		int mn=s[i][0].size(),mx=0;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j])mx=j,mn=min(mn,j);
		}l1[i]=mn,r1[i]=mx;
		for(int j=mn;j<=mx;j++){
			h1[i]=h1[i]*base+s[i][0][j]-'a'+1;
			h1[i]=h1[i]*base+s[i][1][j]-'a'+1;
		}
		p[++len]=h1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size())continue;
		int mn=t[i][0].size(),mx=0;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j])mx=j,mn=min(mn,j);
		}l2[i]=mn,r2[i]=mx;
		for(int j=mn;j<=mx;j++){
			h2[i]=h2[i]*base+t[i][0][j]-'a'+1;
			h2[i]=h2[i]*base+t[i][1][j]-'a'+1;
		}
		p[++len]=h2[i];
	}sort(p+1,p+1+len);len=unique(p+1,p+1+len)-p-1;
	for(int i=1;i<=n;i++)h1[i]=lower_bound(p+1,p+1+len,h1[i])-p,e1[h1[i]].emplace_back(i);
	for(int i=1;i<=q;i++)h2[i]=lower_bound(p+1,p+1+len,h2[i])-p,e2[h2[i]].emplace_back(i);
	for(int i=1;i<=len;i++){
		if(p[i]==0)continue;
		if(e2[i].size()==0)continue;
		for(int j:e1[i]){
			int p=0;
			for(int k=l1[j]-1;k>=0;k--){
				int c=s[j][0][k]-'a';
				if(!nx[p][c])nx[p][c]=++np;
				p=nx[p][c];
			}
			g1[p].emplace_back(j);
			p=1;
			for(int k=r1[j]+1;k<s[j][0].size();k++){
				int c=s[j][0][k]-'a';
				if(!nx[p][c])nx[p][c]=++np;
				p=nx[p][c];
			}id[j]=p;
		}
		for(int j:e2[i]){
			int p=0;
			for(int k=l2[j]-1;k>=0;k--){
				int c=t[j][0][k]-'a';
				if(!nx[p][c])nx[p][c]=++np;
				p=nx[p][c];
			}
			g2[p].emplace_back(j);
		}
		dfs(0);
		cle();
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
