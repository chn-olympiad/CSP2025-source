#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
int lim=200032;
struct fenwick{
	int data[200100];
	inline void add(int x,int y,int z){
		for(;x<=lim;x+=lowbit(x)){
			data[x]+=z;
		}
		for(++y;y<=lim;y+=lowbit(y)){
			data[y]-=z;
		}
	}
	inline int query(int x){
		int rtr=0;
		for(;x>0;x-=lowbit(x)){
			rtr+=data[x];
		}
		return rtr;
	}
}fwtr;
struct trie{
	struct node{
		int end,nxt;
	}edge[2500100];
	struct stct{
		int head,fail,son[28],dep,up,id;
	}data[2500100];
	int cnt,idct,ecnt;
	vector<int> v[200100];
	inline void add(int x,int y){
		++ecnt;
		edge[ecnt]=node{y,data[x].head};
		data[x].head=ecnt;
	}
	inline int insert(int x,char* y){
		int now=0;
		for(int i=0;i<x;++i){
			y[i]-='a';
			if(!data[now].son[y[i]]){
				++cnt;
				data[now].son[y[i]]=cnt;
			}
			now=data[now].son[y[i]];
		}
		if(!data[now].id){
			++idct;
			data[now].id=idct;
		}
		return data[now].id;
	}
	inline void build(){
		queue<int> q;
		for(int i=0;i<27;++i){
			if(data[0].son[i]){
				// cout<<"0-"<<(char)(i+'a')<<"->"<<data[0].son[i]<<endl;
				q.push(data[0].son[i]);
			}
		}
		for(;!q.empty();q.pop()){
			int x=q.front();
			data[x].dep=data[data[x].fail].dep+1;
			// cout<<x<<"  "<<data[x].id<<" "<<data[x].fail<<endl;
			add(data[x].fail,x);
			for(int i=0;i<27;++i){
				if(data[x].son[i]){
					// cout<<x<<"-"<<(char)(i+'a')<<"->"<<data[x].son[i]<<endl;
					data[data[x].son[i]].fail=data[data[x].fail].son[i];
					q.push(data[x].son[i]);
				}else{
					data[x].son[i]=data[data[x].fail].son[i];
				}
			}
		}
	}
	void dfs(int x,int y){
		if(data[x].id){
			v[y].emplace_back(data[x].id);
			// cout<<"--"<<y<<" "<<data[x].id<<endl;
			// add(y,data[x].id);
			y=data[x].id;
		}
		data[x].up=y;
		for(int i=data[x].head;i;i=edge[i].nxt){
			dfs(edge[i].end,y);
		}
	}
	void gen(){
		for(int i=data[0].head;i;i=edge[i].nxt){
			dfs(edge[i].end,0);
		}
	}
}tr1,tr2;
struct stct{
	int pos,id;
};
char ch1[2500100],ch2[2500100];
int n,q,dfncnt,p1[200100],p2[200100],dfn[200100],low[200100];
long long ans[200100];
vector<int> num[200100];
vector<stct> ask[200100];
int fa[28][2500100];
void pre(int x,int y){
	// cout<<"pfa"<<x<<" "<<y<<endl;
	fa[0][x]=y;
	for(int i=1;i<26;++i){
		fa[i][x]=fa[i-1][fa[i-1][x]];
	}
	for(int i=tr1.data[x].head;i;i=tr1.edge[i].nxt){
		pre(tr1.edge[i].end,x);
	}
}
int qfa(int x,int y){
	// cout<<x<<"qfa"<<y<<endl;
	int rtr=x;
	for(;rtr;rtr=tr1.data[rtr].fail){
		if(tr1.data[rtr].dep<=tr1.data[x].dep-y)
		return rtr;
	}
	// cout<<rtr<<endl;
	return 0;
}
void dfs(int x){
	++dfncnt;
	dfn[x]=dfncnt;
	low[x]=dfncnt;
	for(auto i:tr2.v[x]){
		dfs(i);
		low[x]=low[i];
	}
	// cout<<"gdfn"<<x<<"  "<<dfn[x]<<" "<<low[x]<<endl;
}
void calc(int x){
	for(auto i:num[x]){
		fwtr.add(dfn[p2[i]],low[p2[i]],1);
	}
	for(auto i:ask[x]){
		if(i.id<0)
		ans[-i.id]-=fwtr.query(dfn[i.pos]);
		else
		ans[i.id]+=fwtr.query(dfn[i.pos]);
	}
	for(auto i:tr1.v[x]){
		calc(i);
	}
	for(auto i:num[x]){
		fwtr.add(dfn[p2[i]],low[p2[i]],-1);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf(" %s %s",ch1,ch2);
		int t1=strlen(ch1);
		p1[i]=tr1.insert(t1,ch1);
		p2[i]=tr2.insert(t1,ch2);
		num[p1[i]].emplace_back(i);
		// cout<<p1[i]<<"++"<<p2[i]<<endl;
	}
	tr1.build();
	tr1.gen();
	tr2.build();
	tr2.gen();
	pre(0,0);
	// qfa(10,1);
	for(int i=1;i<=q;++i){
		scanf(" %s %s",ch1,ch2);
		int t1=strlen(ch1);
		int lcp=-1,lcs=t1-1;
		for(int j=0;i<t1;++j,++lcp){
			if(ch1[j]!=ch2[j])
			break;
		}
		for(int j=t1-1;~j;--j,--lcs){
			if(ch1[j]!=ch2[j])
			break;
		}
		// cerr<<lcp<<endl;
		int now1=0,now2=0;
		for(int j=0;j<t1;++j){
			now1=tr1.data[now1].son[ch1[j]-'a'];
			now2=tr2.data[now2].son[ch2[j]-'a'];
			int tem=j-lcp-1;
			// cout<<"----"<<tr1.data[now1].dep<<endl;
			if(tr1.data[now1].dep>=tem&&j>=lcs){
				ask[tr1.data[now1].up].emplace_back(stct{tr2.data[now2].up,i});
				// if(tem>0){
				// 	// cout<<now1<<" "<<tr1.data[now1].dep-tem+1<<"  "<<qfa(now1,tr1.data[now1].dep-tem+1)<<endl;
				// 	ask[qfa(now1,tr1.data[now1].dep-tem+1)].emplace_back(stct{tr2.data[now2].up,-i});
				// }
				// cout<<i<<"ask"<<now1<<" "<<now2<<" "<<tr1.data[now1].up<<" "<<tr2.data[now2].up<<endl;
			}
		}
	}
	dfs(0);
	calc(0);
	for(int i=1;i<=q;++i){
		printf("%lld\n",ans[i]);
	}
	return 0;
}