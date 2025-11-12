/*
学了那么久了，有没有一点长进？
但毕竟我也只是一个学了 2 年的小子罢。 
今年的 S 组依旧考的拉跨。 
你熬过的每一个夜晚，刷过的每一道题。
似乎都飘散了，没有留下一点痕迹。
我轻轻的来，正如我轻轻的走。
再见 OI。 
感谢 lxr，thy，hrl 等陪伴，我们一起走过浩瀚的历程，愿你们在NOIP中出色的发挥。
感谢教练的栽培，有缘再见。
哦，现在是 18:26，要提交了。
我的故事就划上了一个句号，也许他们的文章还在继续。
也许这是我人生中忘不掉的吧。
但现在，我必须动身了。
漂泊的旅人歌唱渺茫的希望，余斜的夕阳迎接归途的彷徨。
powered by CQ-S00466 
*/
#include <bits/stdc++.h>

using namespace std;

int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){f=(c=='-'?-1:1);c=getchar();
	}while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();
	}return x*f;
}
#define int long long 
const int N=1e4+10,M=1e6+10+11*N;
int n,m,k;
struct node{
	int u,v,w;
};
vector<node> ed,p;
vector<node> z[N];
int c[N];
int f[N<<1],siz[N];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
bool cmp(node i,node j){
	return i.w<j.w;
}
int solve(int st,vector<node> q){
	int ret=0;
	//memset(vis,0,sizeof vis);
	for(int i=1;i<=(n<<1);i++){
		f[i]=i,siz[i]=1;
	}
	for(int i=0;i<k;i++){
		if(st>>i&1){
			for(auto v:z[i+1]){
				q.push_back(v);
			}
			ret+=c[i+1];
		}
	}
	sort(q.begin(),q.end(),cmp);
	for(auto edge:q){
		int u=edge.u,v=edge.v,w=edge.w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		//f[fu]=fv;
		if(siz[fu]<=siz[fv]){
			f[fu]=fv;
			siz[fv]+=siz[fu];
		}
		else{
			f[fv]=fu;
			siz[fu]+=siz[fv];
		}
		ret+=w; 
	}
	return ret;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		ed.push_back({u,v,w});
	}
	if(k==0){
		sort(ed.begin(),ed.end(),cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		int ret=0;
		for(int i=1;i<=m;i++){
			int u=ed[i-1].u,v=ed[i-1].v;
			int fu=find(u),fv=find(v);
			if(fu==fv){
				continue;
			}
			f[fu]=fv;
			ret+=ed[i-1].w;
		}
		cout<<ret;
		return 0;
	}
	bool f=0; 
	p=ed;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0) f=1;
		for(int j=1;j<=n;j++){
			int x=read();
			z[i].push_back({i+n,j,x});
			if(x!=0) f=1;
		}
	}
	int ret=1e9;
	for(int i=0;i<(1<<k);i++){
		ret=min(ret,solve(i,ed));
	}
	cout<<ret;
	return 0;
}
//我该在哪里停留？我问我自己。 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 5 0
1 2 2
1 3 1
1 4 3
3 4 6
2 4 5
*/

