bool St;
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define lbt(x) ((x)&(-(x)))
#define N 5000006
#define mod1 998442353
#define mod2 998244353
#define B 233
int cto[27][27],vl[N],vr[N],sz[N];
vector<int> a[400005];
ll p1[N],p2[N];
vector<ll> hsh1[400005],hsh2[400005];
inline ll gethsh(ll hs1,ll hs2){
	return hs1*1000000000ll+hs2;
}
map<ll,vector<int> > tong;
inline ll hshlr(int i,int l,int r){
	return gethsh(((hsh1[i][r]-(l?hsh1[i][l-1]*p1[r-l+1]:0)%mod1)%mod1+mod1)%mod1,
	((hsh2[i][r]-(l?hsh2[i][l-1]*p2[r-l+1]:0)%mod2)%mod2+mod2)%mod2);
}
inline bool chk(int v1,int v2){
	//cerr<<"NOW: "<<v2<<"  "<<vl[v1]<<" "<<vl[v2]<<endl;
	//if((vl[v1]<vl[v2])||((sz[v1]-vr[v1])<(sz[v2]-vr[v2])))	return 0;
	//cerr<<v2<<endl;
	//if(((!vl[v1])?0:hshlr(v1,vl[v1]-vl[v2],vl[v1]-1))!=((!vl[v2])?0:hshlr(v2,0,vl[v2]-1)))	return 0;
	//cerr<<"NOW: "<<v2<<" : "<<vr[v1]+1<<" "<<vr[v1]+(sz[v2]-vr[v2])<<"   "<<vr[v2]+1<<" "<<sz[v2]<<endl;
	//cerr<<"THIS: "<<v2<<" "<<hshlr(v1,vr[v1]+1,vr[v1]+(sz[v2]-vr[v2]))<<" "<<hshlr(v2,vr[v2]+1,sz[v2])<<endl;
	//if(hshlr(v1,vr[v1]+1,vr[v1]+(sz[v2]-vr[v2]))!=hshlr(v2,vr[v2]+1,sz[v2]))	return 0;
	//cerr<<"CAN"<<endl;
	return 1;
}
bool En;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//cerr<<(&St-&En)/1024.0/1024.0<<"MB"<<endl;
	for(int i=1;i<=26;i++){
		for(int j=1;j<=26;j++){
			cto[i][j]=(i-1)*26+j;
		}
	}
	p1[0]=p2[0]=1;
	for(int i=1;i<=5000000;i++){
		p1[i]=(p1[i-1]*B)%mod1;p2[i]=(p2[i-1]*B)%mod2;
	}
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;sz[i]=s1.size()-1;
		a[i].resize(s1.size()+2);hsh1[i].resize(s1.size()+2);hsh2[i].resize(s1.size()+2);
		for(int j=0;j<s1.size();j++){
			a[i][j]=cto[s1[j]-'a'+1][s2[j]-'a'+1];
			hsh1[i][j]=((j?hsh1[i][j-1]:0ll)*B%mod1+a[i][j])%mod1;
			hsh2[i][j]=((j?hsh2[i][j-1]:0ll)*B%mod2+a[i][j])%mod2;
		}
		vl[i]=0;vr[i]=s1.size()-1;
		while((vl[i]<s1.size()-1)&&(s1[vl[i]]==s2[vl[i]])){
			vl[i]++;
		}
		while((vr[i]>=vl[i])&&(s1[vr[i]]==s2[vr[i]])){
			vr[i]--;
		}
		if(vl[i]>vr[i])	continue;
		tong[hshlr(i,vl[i],vr[i])].push_back(i);
	}
	int t=n+1;
	while(q--){
		string s1,s2;cin>>s1>>s2;sz[t]=s1.size()-1;
		a[t].resize(s1.size()+2);hsh1[t].resize(s1.size()+2);hsh2[t].resize(s1.size()+2);
		int l=0;int r=s1.size()-1;
		while((l<s1.size()-1)&&(s1[l]==s2[l]))	l++;
		while((r>=l)&&(s1[r]==s2[r]))	r--;
		for(int j=0;j<s1.size();j++){
			a[t][j]=cto[s1[j]-'a'+1][s2[j]-'a'+1];
			hsh1[t][j]=((j?hsh1[t][j-1]:0ll)*B%mod1+a[t][j])%mod1;
			hsh2[t][j]=((j?hsh2[t][j-1]:0ll)*B%mod2+a[t][j])%mod2;
		}
		ll v=hshlr(t,l,r);vector<int> tmp=tong[v];
		/*int sum=0;
		for(int i=0;i<tmp.size();i++){
			int pos=tmp[i];sum+=chk(t,pos);
		}
		cout<<sum<<"\n";*/
		cout<<tmp.size()<<"\n";
	}
	return 0;
}
/*
ÂÒ¸ã£¡¹þÏ£Õâ±ßÓÃË«Ä£ 
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
