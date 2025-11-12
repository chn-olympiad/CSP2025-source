#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 200010
const int mod=998442353,base=13331;
int n,q,idx,ans[N],pre[N],suf[N],pree[N],suff[N],bas2[N],hsh2[N],hshh2[N],has2[N];
unsigned int hsh1[N],bas1[N],hshh1[N],has1[N];
string s[N][2],t[N][2];
unordered_map<int,int>mp;
vector<int>gua[N],h2[N];
vector<unsigned int>h1[N];
unsigned int gth1(int id,int l,int r){return h1[id][r]-h1[id][l-1]*bas1[r-l+1];}
int gth2(int id,int l,int r){return (h2[id][r]-h2[id][l-1]*bas2[r-l+1]%mod+mod)%mod;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	bas1[0]=bas2[0]=1;
	rep(i,1,200000){bas1[i]=bas1[i-1]*base;bas2[i]=bas2[i-1]*base%mod;}
	cin>>n>>q;
	rep(i,1,n){cin>>s[i][0]>>s[i][1];}
	rep(i,1,q){cin>>t[i][0]>>t[i][1];}
	rep(i,1,n){
		pre[i]=-1;
		rep(j,0,s[i][0].size()-1){
			has1[i]=has1[i]*base+s[i][0][j];
			has2[i]=(has2[i]*base%mod+s[i][0][j])%mod;
		}
		rep(j,0,s[i][0].size()-1){
			if(s[i][0][j]!=s[i][1][j]){pre[i]=j;break;}
		}
		if(pre[i]==-1){continue;}
		per(j,s[i][0].size()-1,0){
			if(s[i][0][j]!=s[i][1][j]){suf[i]=j;break;}
		}
		unsigned int h1=0;
		int h2=0;
		rep(j,pre[i],suf[i]){
			hsh1[i]=hsh1[i]*base+s[i][0][j];
			h1=h1*base+s[i][1][j];
			hsh2[i]=(hsh2[i]*base+s[i][0][j])%mod;
			h2=(h2*base+s[i][1][j])%mod;
		}
		unsigned int hh1=0;int hh2=0;
		hh1=hsh1[i]*bas1[suf[i]-pre[i]+1]+h1;
		hh2=(hsh2[i]*bas2[suf[i]-pre[i]+1]%mod+h2)%mod;
		unsigned int hsh=hh1*1000000009ll+hh2,id;
		if(!mp[hsh]){idx++;mp[hsh]=idx;}
		id=mp[hsh];
		gua[id].push_back(i);
	}
	rep(i,1,q){
		if(t[i][0].size()!=t[i][1].size()){cout<<0<<'\n';continue;}
		pree[i]=-1;
		rep(j,0,t[i][0].size()-1){if(t[i][0][j]!=t[i][1][j]){pree[i]=j;break;}}
		if(pree[i]==-1){cout<<0<<'\n';continue;}
		per(j,t[i][0].size()-1,0){if(t[i][0][j]!=t[i][1][j]){suff[i]=j;break;}}
		h1[i].resize(t[i][0].size()+1);
		h2[i].resize(t[i][0].size()+1);
		rep(j,1,t[i][0].size()){
			h1[i][j]=h1[i][j-1]*base+t[i][0][j-1];
			h2[i][j]=(h2[i][j-1]*base%mod+t[i][0][j-1])%mod;
		}
		unsigned int h1=0;
		int h2=0;
		rep(j,pree[i],suff[i]){
			hshh1[i]=hshh1[i]*base+t[i][0][j];
			h1=h1*base+t[i][1][j];
			hshh2[i]=(hshh2[i]*base%mod+t[i][0][j])%mod;
			h2=(h2*base%mod+t[i][1][j])%mod;
		}
		hshh1[i]=hshh1[i]*bas1[suff[i]-pree[i]+1]+h1;
		hshh2[i]=(hshh2[i]*bas2[suff[i]-pree[i]+1]%mod+h2)%mod;
		unsigned int hsh=hshh1[i]*1000000009ll+hshh2[i],id;
		id=mp[hsh];
		if(!id){cout<<0<<'\n';continue;}
		int nums=0;
		for(int j:gua[id]){
			int le=pree[i]-pre[j],ri=suff[i]+(s[j][0].size()-1-suf[j]);
			if(le<0||ri>=t[i][0].size()){continue;}
			if(has1[j]==gth1(i,le+1,ri+1)&&has2[j]==gth2(i,le+1,ri+1)){
				nums++;
			}
		}
		cout<<nums<<'\n';
	}
	return 0;
}
