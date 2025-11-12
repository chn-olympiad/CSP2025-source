#include<bits/stdc++.h>
using namespace std;
namespace ld{
	typedef long long ll;
	const int N=5e5+5;
	int n,Q;
	int cnt,ch[N][26][26],bj[N],nxt[N],Len[N];
	vector<int>ed[N];
	void fail(){
		queue<int>q;
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)if(ch[0][i][j])q.push(ch[0][i][j]);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++){
					if(!ch[u][i][j])ch[u][i][j]=ch[nxt[u]][i][j];
					else nxt[ch[u][i][j]]=ch[nxt[u]][i][j],q.push(ch[u][i][j]);
				}
		}	
		for(int i=1;i<=cnt;i++)ed[nxt[i]].push_back(i);
	}
	int sum[N],to[N];
	int f[N][21];
	void Dfs(int u,int up){
		sum[u]=sum[nxt[u]]+bj[u];
		f[u][0]=to[u]=up;
		for(int v:ed[u])Dfs(v,(bj[u]?u:up));
	}
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>n>>Q;
		for(int i=1;i<=n;i++){
			string s1,s2;
			cin>>s1>>s2;
			int p=0;
			for(int j=0;j<s1.length();j++){
				if(!ch[p][s1[j]-'a'][s2[j]-'a'])ch[p][s1[j]-'a'][s2[j]-'a']=++cnt;
				p=ch[p][s1[j]-'a'][s2[j]-'a'];
			}
			++bj[p],Len[p]=s1.length();
		}
		fail(),Dfs(0,0);
		for(int j=1;j<=__lg(cnt);j++)
			for(int i=1;i<=cnt;i++)f[i][j]=f[f[i][j-1]][j-1];
		while(Q--){
			ll res=0;
			string s1,s2;
			cin>>s1>>s2;
			if(s1.length()!=s2.length()){
				cout<<0<<'\n';
				continue;
			}
			int len=s1.length();
			int lcp=0;
			for(int i=0;i<len;i++){
				if(s1[i]==s2[i]){
					++lcp;
				}else break;
			}
			int lcp2=0;
			for(int i=len-1;i>=0;i--){
				if(s1[i]==s2[i]){
					++lcp2;
				}else break;				
			}
			int p=0;
			for(int i=0;i<s1.length();i++){
				p=ch[p][s1[i]-'a'][s2[i]-'a'];
				if(i>=len-lcp2-1){
					int x=(bj[p]?p:to[p]),ox=x;
					if(Len[x]<i-lcp+1)continue;
					for(int j=__lg(cnt);j>=0;j--){
						int nx=f[x][j];
						if(Len[nx]<i-lcp+1)continue;
						x=nx;
					}
					res+=sum[ox]-sum[nxt[x]];
				}
			}			
			cout<<res<<'\n';
		}
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
//¿Õ¼ä:1390mb/2048mb
//Ê±¼ä:s/1s
