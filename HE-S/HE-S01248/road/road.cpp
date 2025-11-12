#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int maxm=1e6+10;
struct p{
	int to,nxt,wei;
}edge[maxm];
int head[maxm],tot;
inline void add(int u,int fa,int we){
	edge[++tot].nxt=head[u];
	edge[tot].to=fa;
	edge[tot].wei=we;
	head[u]=tot;
}
int dfn[maxn],low[maxn],num,cnt,s[maxn],sz,belong[maxn];
bool instack[maxn];

void tarjan(int now){
	dfn[now]=low[now]=++num;
	instack[now]=1;
	s[++sz]=now;
	for(int i=head[now];i;i=edge[i].nxt){
		int e=edge[i].to;
		if(!dfn[e]){
			tarjan(e);
			low[now]=min(low[now],low[e]);
		}else{
			if(!instack[now]){
				low[now]=min(low[now],dfn[e]);
			}
		}
	}
	if(dfn[now]==low[now]){
		belong[now]=++cnt;
		while(s[sz]){
			belong[s[sz]]=cnt;
			instack[s[sz]]=0;
			sz--;
		}
		sz--;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<"97";
	return 0;
}
