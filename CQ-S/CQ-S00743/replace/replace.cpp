#include<bits/stdc++.h>
using namespace std;
bool _Be;
int n,q,len[200005],ql[200005],qv[200005],id[200005],sL[200005],sR[200005];
struct node{
	int l,v;
	bool operator<(const node &t)const{return l<t.l||(l==t.l&&v<t.v);}
	bool operator==(const node &t)const{return l==t.l&&v==t.v;}
}pv[200005],av[200005],tv[200005];
int tot;
string s[200005][2],t[2];
bool vis[5000005];
const int base=13331,mod=998244853;
struct ACAM{
	int rt[200005],cnt;
	struct Node{
		int son[27],fa,fail,val;
	}c[10000005];
	int New(int fa=0){
		cnt++;
		memset(c[cnt].son,0,sizeof(c[cnt].son));
		c[cnt].fail=0;
		c[cnt].fa=fa;
		c[cnt].val=0;
		return cnt;
	}
	void Insert(int id,string &s){
		int len=s.length();
		if(!rt[id])rt[id]=New();
		int q=rt[id];
		for(int j=0;j<len;j++){
			int op=s[j]-'a';
			if(!c[q].son[op])c[q].son[op]=New(q);
			q=c[q].son[op];
		}
		c[q].val++;
	}
	void Build(int id){
		queue<int>q;
		for(int i=0;i<27;i++){
			if(c[rt[id]].son[i]){
				int v=c[rt[id]].son[i];
				c[v].fail=rt[id];
				q.push(v);
			}
			else c[rt[id]].son[i]=rt[id];
		}
		while(!q.empty()){
			int tmp=q.front();
			q.pop();
			c[tmp].val+=c[c[tmp].fail].val;
			for(int i=0;i<27;i++){
				int v=c[tmp].son[i];
				if(v){
					c[v].fail=c[c[tmp].fail].son[i];
					q.push(v);
				}
				else c[tmp].son[i]=c[c[tmp].fail].son[i];
			}
		}
	}
	int Get(int id,string &s){
		int res=0,q=rt[id],len=s.length();
		for(int i=0;i<len;i++){
			int op=s[i]-'a';
			q=c[q].son[op];
			res+=c[q].val;
		}
		return res;
	}
}T;
bool _Ed;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++){
		len[i]=s[i][0].length();
		for(int j=0;j<len[i];j++)vis[j]=(s[i][0][j]==s[i][1][j]);
		int L=len[i],R=0;
		for(int j=0;j<len[i];j++){
			if(!vis[j]){
				L=min(L,j);
				R=j;
			}
		}
		ql[i]=R-L+1;
		for(int j=L;j<=R;j++){
			qv[i]=(1ll*qv[i]*base%mod+(s[i][0][j]-'a')*26+(s[i][1][j]-'a'))%mod;
		}
		pv[++tot]=node({ql[i],qv[i]});
//		cerr<<ql[i]<<" "<<qv[i]<<endl;
		av[i]=pv[tot];
		sL[i]=L;
		sR[i]=R;
	}
	sort(pv+1,pv+tot+1);
	tot=unique(pv+1,pv+tot+1)-pv-1;
	for(int i=1;i<=n;i++){
		id[i]=lower_bound(pv+1,pv+tot+1,av[i])-pv;
		string sp="";
		for(int j=0;j<=sL[i]-1;j++)sp+=s[i][0][j];
		sp+='{';
		for(int j=sR[i]+1;j<len[i];j++)sp+=s[i][0][j];
//		cerr<<i<<' '<<id[i]<<' '<<sp<<endl;
		T.Insert(id[i],sp);
	}
//	for(int i=1;i<=n;i++)cerr<<id[i]<<' ';
//	cerr<<endl;
	for(int i=1;i<=tot;i++)T.Build(i);
	while(q--){
		cin>>t[0]>>t[1];
		int tl=t[0].length();
		for(int i=0;i<tl;i++){
			vis[i]=(t[0][i]==t[1][i]);
		}
		int L=tl,R=0;
		for(int i=0;i<tl;i++){
			if(!vis[i]){
				L=min(L,i);
				R=i;
			}
		}
		int sl=R-L+1,sv=0;
		for(int i=L;i<=R;i++){
			sv=(1ll*sv*base%mod+(t[0][i]-'a')*26+(t[1][i]-'a'))%mod;
		}
//		cerr<<sl<<' '<<sv<<endl;
		node tid=node({sl,sv});
		int pos=lower_bound(pv+1,pv+tot+1,tid)-pv;
		if(tid==pv[pos]){
			string sp="";
			for(int i=0;i<=L-1;i++)sp+=t[0][i];
			sp+='{';
			for(int i=R+1;i<tl;i++)sp+=t[0][i];
//			cerr<<pos<<" "<<sp<<endl;
			cout<<T.Get(pos,sp)<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
}
