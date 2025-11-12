#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
using namespace std;
namespace Yukina{
	inline int read(){
		int ans=0,w=1;
		char ch=getchar();
		while(ch<48||ch>57){
			if(ch=='-')w=-1;
			ch=getchar();
		}
		while(ch>=48&&ch<=57){
			ans=(ans<<1)+(ans<<3)+ch-48;
			ch=getchar();
		}
		return w*ans;
	}
	inline void read(string &s){
		s.clear();
		s+='0';
		char ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z'){
			s+=ch;
			ch=getchar();
		}
	}
	int n,Q;
	const ull base=1145141;
	ull P[5000005];
	struct node{
		string s1,s2;
		int len,L,R;
	}a[200005];
	struct query{
		string s1,s2;
		int len,L,R;
	}q[200005];
	struct Ran{
		int len;
		ull h1,h2;
		bool operator<(const Ran &a)const{
			if(len!=a.len)return len<a.len;
			if(h1!=a.h1)return h1<a.h1;
			return h2<a.h2;
		}
	};
	map<Ran,vector<int> >t1,t2;//len,hash 
	int tim;
	unordered_map<ull,int>id;
	int fa[200005];
	vector<int>e[200005];//边 
	vector<pair<int,ull> >ver[200005];//每个节点上有哪些标记 
	vector<int>que[200005];//每个节点上有哪些询问 
	ll ans[200005];
	
	unordered_map<ull,int>cnt[5000005];
	void dfs(int x){
		for(auto i:ver[x])++cnt[i.first][i.second];//cerr<<x<<' '<<i<<'\n';
		for(int i:que[x]){//遍历询问
			ans[i]=cnt[0][0];
			ull h=0;
			for(int j=q[i].R+1;j<=q[i].len;j++){
				h=h*base+q[i].s1[j];
//				cerr<<i<<" "<<j<<' '<<h<<'\n';
				ans[i]+=cnt[j-q[i].R][h];
			} 
		}
		for(int v:e[x])dfs(v);
		for(auto i:ver[x])--cnt[i.first][i.second];
	}
	int main(){
		P[0]=1;
		for(int i=1;i<=5000000;i++)P[i]=P[i-1]*base;
		n=read(),Q=read();
		for(int i=1;i<=n;i++)read(a[i].s1),read(a[i].s2);
		for(int i=1;i<=Q;i++)read(q[i].s1),read(q[i].s2);
		for(int i=1;i<=n;i++){
			a[i].len=a[i].s1.size()-1;
			if(a[i].s1==a[i].s2)continue;
			int L=1e9,R=-1e9;
			for(int j=1;j<=a[i].len;j++){
				if(a[i].s1[j]!=a[i].s2[j])L=min(L,j),R=max(R,j);
			}
			a[i].L=L,a[i].R=R;
			ull h1=0,h2=0;
			for(int j=L;j<=R;j++)h1=h1*base+a[i].s1[j],h2=h2*base+a[i].s2[j];
			
			t1[{R-L+1,h1,h2}].push_back(i);
		}//插入这些替换的东西 
		
		for(int i=1;i<=Q;i++){
			if(q[i].s1.size()!=q[i].s2.size())continue;
			q[i].len=q[i].s1.size()-1;
			int L=1e9,R=-1e9;
			for(int j=1;j<=q[i].len;j++){
				if(q[i].s1[j]!=q[i].s2[j])L=min(L,j),R=max(R,j);
			}
			q[i].L=L,q[i].R=R;
			ull h1=0,h2=0;
			for(int j=L;j<=R;j++)h1=h1*base+q[i].s1[j],h2=h2*base+q[i].s2[j];
			t2[{R-L+1,h1,h2}].push_back(i);
		}
		for(auto p:t2){
			Ran now=p.first;
			vector<int> qu=p.second;//当前的询问
			if(t1.find(now)==t1.end())continue;
			vector<int> op=t1[now];//当前的操作，那些替换
			//现在，那些替换将 s1 对应的后缀给连一条边 
			//询问即变成祖先链的字符串查询 
			if(!op.size())continue;
			
//			cerr<<"-----\n";
//			for(int i:qu)cerr<<i<<' '<<q[i].L<<' '<<q[i].R<<'\n';
//			cerr<<'\n';
//			for(int i:op)cerr<<i<<' '<<a[i].L<<' '<<a[i].R<<'\n';
//			cerr<<'\n';
			tim=0,id[0]=0;
			sort(op.begin(),op.end(),[&](int x,int y){
				return a[x].L<a[y].L;
			});
			for(int i:op){//处理操作，建边 
				ull h1=0,h2=0;
				for(int j=1;j<a[i].L;j++)h1=h1*base+a[i].s1[j];
				for(int j=a[i].R+1;j<=a[i].len;j++)h2=h2*base+a[i].s1[j];
//				cerr<<"*** "<<i<<" "<<h1<<' '<<h2<<'\n';
				if(id.find(h1)!=id.end()){
					ver[id[h1]].push_back({a[i].len-a[i].R,h2});
					continue;
				}
				int now=1;
				ull hf=h1;
				while(now<a[i].L&&id.find(hf)==id.end())hf=hf-a[i].s1[now]*P[a[i].L-now-1],++now;
				id[h1]=++tim;
				fa[tim]=id[hf];
				e[id[hf]].push_back(tim);
				ver[tim].push_back({a[i].len-a[i].R,h2});
//				cerr<<i<<' '<<h1<<' '<<id[h1]<<' '<<fa[id[h1]]<<'\n';
			}
			for(int i:qu){
				ull h1=0;
				for(int j=1;j<q[i].L;j++)h1=h1*base+q[i].s1[j];
				if(id.find(h1)!=id.end()){
					que[id[h1]].push_back(i);
					continue;
				}
				int now=1;
				ull hf=h1;
				while(now<q[i].L&&id.find(hf)==id.end())hf=hf-q[i].s1[now]*P[q[i].L-now-1],++now;
				que[id[hf]].push_back(i);
			}
			dfs(0);
			
			id.clear();
			for(int i:op)cnt[a[i].len-a[i].R].clear();
			for(int i=0;i<=tim;i++)ver[i].clear(),que[i].clear(),e[i].clear(),fa[i]=0;
			tim=0;
		}
		for(int i=1;i<=Q;i++)cout<<ans[i]<<'\n';
//		while(1);
		return 0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return Yukina::main();
}
//374MB
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
