#include<bits/stdc++.h>
using namespace std;
struct Trie{
	int ch[26];
};
const int S=5e6,N=2e5;
struct Point{
	int x,y,val;
}ad[800005];
bool cmp(Point x,Point y){
	return x.x<y.x;
}
queue<int>q;
string str;
struct ACAM{
	int dfn[S+5],siz[S+5];
	int tot,nxt[S+4][26],fail[S+5];
	Trie a[S+5];
	vector<int>vec[S+5];
	int insert(){
		int p=1;
		for(int i=0;i<str.size();i++){
			int ch=str[i]-'a';
			if(a[p].ch[ch]==0)a[p].ch[ch]=++tot;
			p=a[p].ch[ch];
		}
		return p;
	}
	void init(){
		for(int i=1;i<=tot;i++){
			for(int j=0;j<26;j++)nxt[i][j]=a[i].ch[j]=0;
			vec[i].clear();
			fail[i]=0;
			dfn[i]=siz[i]=0;
		}
		tot=1;
	}
	void build(){
		fail[1]=1;
		for(int i=0;i<26;i++){
			if(a[1].ch[i]){
				q.push(a[1].ch[i]);
				fail[a[1].ch[i]]=1;
				nxt[1][i]=a[1].ch[i];
			}else nxt[1][i]=1;
		}
		while(!q.empty()){
			int u=q.front();q.pop();
//			cout<<u<<"\n";
			for(int i=0;i<26;i++){
				int v=a[u].ch[i];
				if(v==0){
					nxt[u][i]=nxt[fail[u]][i];
					continue;
				}
				nxt[u][i]=v;
				fail[v]=nxt[fail[u]][i];
//				cout<<"push"<<v<<"\n";
				q.push(v);
			}
		}
		for(int i=2;i<=tot;i++)vec[fail[i]].push_back(i);tot=0;
	}
	void dfs(int u){
		dfn[u]=++tot;siz[u]=1;
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i];
			if(dfn[v])continue;
			dfs(v);
			siz[u]+=siz[v];
		}
	}
}AC;
int lowbit(int u){
	return u&(-u);
}
int lim;
long long f[5000005];
void add(int u,int k){
	for(int i=u;i<=lim;i+=lowbit(i))f[i]+=k;
}
long long query(int k){
	long long ans=0;
	for(int i=k;i>=1;i-=lowbit(i))ans+=f[i];
	return ans;
}
vector<pair<int,int> >vec[5000005];
vector<int>vec2[5000005];
int n,m,dtot;
int a[200005];
long long ans[200005],l[200005],r[200005];
string str2,S2[2][200005],T[2][200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>S2[0][i]>>S2[1][i];
	}
	AC.tot=1;
	for(int i=1;i<=n;i++){
		str=S2[0][i];
		a[i]=AC.insert();
	}
	lim=AC.tot;
	AC.build();
	AC.dfs(1);
	for(int i=1;i<=n;i++)l[i]=AC.dfn[a[i]],r[i]=AC.dfn[a[i]]+AC.siz[a[i]];
	for(int i=1;i<=AC.tot;i++){
//		for(int j=0;j<26;j++)cout<<AC.a[i].ch[j]<<" ";
		cout<<AC.dfn[i]<<" ";
//		cout<<"\n";
	}cout<<"\n";
	for(int i=1;i<=m;i++){
//		cin>>str>>str2;
		cin>>T[0][i]>>T[1][i];
		str=T[0][i];str2=T[1][i];
		if(str.size()!=str2.size())continue;
		int len=str.size(),nt=len-1;
		for(;str[nt]==str2[nt];nt--);
		int rt1=1;
		for(int j=0;j<len;j++){
			rt1=AC.nxt[rt1][str[j]-'a'];
//			rt2=AC.nxt[rt2][str2[j]-'a'];
			if(nt<=j)vec2[i].push_back(AC.dfn[rt1]);
		}
	}
	AC.init();
	
	for(int i=1;i<=n;i++){
		str=S2[1][i];
		a[i]=AC.insert();
	}
	AC.build();AC.dfs(1);
	for(int i=1;i<=AC.tot;i++){
//		for(int j=0;j<26;j++)cout<<AC.a[i].ch[j]<<" ";
		cout<<AC.dfn[i]<<" ";
//		cout<<"\n";
	}
	cout<<'\n';
	for(int i=1;i<=m;i++){
		str=T[0][i];str2=T[1][i];
		if(T[0][i].size()!=T[1][i].size())continue;
		int len=str.size(),nt=len-1;
		for(;str[nt]==str2[nt];nt--);
		int rt2=1;
		int pos=0;
		for(int j=0;j<len;j++){
//			rt1=AC.nxt[rt1][str[j]-'a'];
			rt2=AC.nxt[rt2][str2[j]-'a'];
			if(nt<=j){
				vec[vec2[i][pos]].push_back({AC.dfn[rt2],i});
				pos++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int id2=a[i];
		cout<<l[i]<<" "<<r[i]<<" "<<AC.dfn[id2]<<" "<<AC.dfn[id2]+AC.siz[id2]<<"\n";
		ad[++dtot]={l[i],AC.dfn[id2],1};
		ad[++dtot]={r[i],AC.dfn[id2]+AC.siz[id2],1};
		ad[++dtot]={r[i],AC.dfn[id2],-1};
		ad[++dtot]={l[i],AC.dfn[id2]+AC.siz[id2],-1};
	}
	lim=max(lim,AC.tot);
	int pos=1;
	sort(ad+1,ad+dtot+1,cmp);
	for(int i=1;i<=lim;i++){
		while(pos<=dtot&&ad[pos].x<=i){
			add(ad[pos].y,ad[pos].val);
			pos++;
		}
		for(int j=0;j<vec[i].size();j++){
			cout<<"Query"<<vec[i][j].second<<" "<<vec[i][j].first<<'\n';
			ans[vec[i][j].second]+=query(vec[i][j].first);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<'\n';
	}
	return 0; 
}
/*
3 1
ab cd
bc de
aa bb
aaaa bbbb
哎，显然我写假了，

204pts，不如去年，关注553501谢谢喵。

再也不写难度大题时不检查正确性了，用样例手摸一下都知道是错 的这辈子有了。如果能参加NOIP的话，就再也不敢啦！ 
*/
