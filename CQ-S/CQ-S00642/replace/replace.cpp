#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s[200005][2];
struct node{
	int trie[5000005][26],tot=1,f[5000005],dep[5000005],vis[5000005];
	int insert(string a){
		int rt=1;
		for(int i=0;i<a.size();i++){
			if(!trie[rt][a[i]-'a'])trie[rt][a[i]-'a']==++tot,dep[tot]=dep[rt]+1;
			rt=trie[rt][a[i]-'a'];
		}
		vis[rt]=1;
		return rt;
	}
	void bld(){
		queue<int>q;
		for(int i=0;i<26;i++){
			if(trie[1][i]){
				q.push(trie[1][i]);
			}
			if(trie[0][i]){
				q.push(trie[0][i]);
			}
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i=0;i<26;i++){
				int v=trie[u][i];
				if(!v)continue;
				int now=f[u];
				while(now!=1&&!trie[now][i])now=f[now];
				if(trie[now][i])now=trie[now][i];
				f[v]=now;
				q.push(v);
			}
		}
	}
}t[2];
map<pair<int,int>,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int p1=t[0].insert(s[i][0]);
		int p2=t[1].insert(s[i][1]);
		++mp[{p1,p2}];
	}
	t[0].bld();
	t[1].bld();
	while(m--){
		string q[2];
		cin>>q[0]>>q[1];
		int p1=1,p2=1,l=-1,r,ans=0;
		for(int i=0;i<q[0].size();i++){
			if(q[0][i]!=q[1][i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		for(int i=0;i<q[0].size();i++){
			while(!t[0].trie[p1][q[0][i]-'a']&&p1!=1)p1=t[0].f[p1];
			while(!t[1].trie[p2][q[1][i]-'a']&&p2!=1)p2=t[1].f[p2];
			if(t[0].trie[p1][q[0][i]-'a'])p1=t[0].trie[p1][q[0][i]-'a'];
			if(t[1].trie[p2][q[1][i]-'a'])p2=t[1].trie[p2][q[1][i]-'a'];
			while(t[0].dep[p1]>t[0].dep[p2])p1=t[0].f[p1];
			while(t[1].dep[p1]<t[1].dep[p2])p1=t[1].f[p2];
			if(i>=r&&i-t[0].dep[p1]+1<=l)ans+=mp[{p1,p2}];
		}
		cout<<ans<<endl;
	}
	return 0;
}
