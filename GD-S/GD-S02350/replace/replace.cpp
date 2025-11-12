#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=200005,M=10000007,MOD=998244853,p=131;
int n,q,mi[M],s[M][27],cnt,root,ans[N];
string s1,s2,t1[N],t2[N];
vector<pair<int,int> > g[M];
vector<int>pp[M];
map<pair<int,int>,int> mp;
void inter(int &u,int c,pair<int,int> w,int d){
	if(!u)u=++cnt;
	if(c>=0){
		if(d==0)inter(s[u][s1[c]-'a'+1],c-1,w,d);
		else inter(s[u][t1[d][c]-'a'+1],c-1,w,d);
	}else{
		if(d==0)g[u].push_back(w);
		else pp[u].push_back(d);
//		cout<<u<<" "<<d<<" "<<w.fi<<" "<<w.se<<" @@@\n";
	}
}
void dfs(int u){
	for(int i=0;i<g[u].size();i++){
		pair<int,int> x=g[u][i];
//		if(x.fi<0||x.se<0)cout<<"???\n";
		mp[x]++;
	}
	
	
	for(int i=0;i<pp[u].size();i++){
		int id=pp[u][i];
		int mn=1e9,mx=-1;
		for(int j=0;j<t1[id].size();j++){
			if(t1[id][j]!=t2[id][j]){
				mn=min(mn,j),mx=max(mx,j);
			}
		}
		int w1=0,w2=0;
		for(int j=mn;j<t1[id].size();j++){
			w1=(w1+1ll*mi[j-mn]*t1[id][j]%MOD)%MOD;
			w2=(w2+1ll*mi[j-mn]*t2[id][j]%MOD)%MOD;
			if(j>=mx){
				ans[id]+=mp[mk(w1,w2)];
//				cout<<u<<" "<<id<<" "<<w1<<" "<<w2<<" "<<mp[mk(w1,w2)]<<" ###\n";
			}
		}
	}
	for(int i=1;i<=26;i++){
		if(s[u][i]!=0){
//			cout<<u<<" "<<s[u][i]<<" %%%\n";
			dfs(s[u][i]);
		}
	}
	
	for(int i=0;i<g[u].size();i++){
		pair<int,int> x=g[u][i];
		mp[x]--;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	mi[0]=1;
	for(int i=1;i<M;i++){
		mi[i]=1ll*mi[i-1]*p%MOD;
	}
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int mn=1e9;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				mn=min(mn,j);
			}
		}
		if(mn==1e9)continue;
		
//		cout<<i<<" "<<mn<<" !!!\n";
		int w1=0,w2=0;
		for(int j=mn;j<s1.size();j++){
			w1=(w1+1ll*mi[j-mn]*s1[j]%MOD)%MOD;
			w2=(w2+1ll*mi[j-mn]*s2[j]%MOD)%MOD;
		}
		inter(root,mn-1,mk(w1,w2),0);
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		int mn=1e9;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!=t2[i][j]){
				mn=min(mn,j);
			}
		}
//		cout<<i<<" "<<cnt<<" ???\n";
		inter(root,mn-1,mk(0,0),i);
	}
//	cout<<"___________\n";
	dfs(root);
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
}
