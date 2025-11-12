#include<bits/stdc++.h>
#define MAXN 20005
#define MAXK 15
#define int long long

using namespace std;
namespace FastIO
{
	inline string _rs()
	{
		string str="";
		int ch=getchar();
		while(ch==' ' || ch=='\n' || ch=='\r') ch=getchar();
		while(ch!=' ' && ch!='\n' && ch!='\r' && ch!=EOF){
			str.push_back(ch);
			ch=getchar();
		}
		return str;
	}
	inline void _ws(string a,char b)
	{
		int len=a.size();
		for(int i=0;i<len;i++) putchar(a[i]);
		putchar(b);
		return ;
	}
	inline int _r()
	{
		int flag=1,ans=0,ch=getchar();
		while((ch<'0' || ch>'9') && ch!=EOF){
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0' && ch<='9'){
			ans=(ans<<1)+(ans<<3)+(ch^48);
			ch=getchar();
		}
		return flag*ans;
	}
	inline void _w(int a,char b)
	{
		if(a<0) a=-a,putchar('-');
		int sta[22],top=0;
		do{
			sta[top++]=a%10;
			a/=10;
		}while(a);
		while(top) putchar(sta[--top]+48);
		putchar(b);
		return ;
	}
}
using namespace FastIO;

struct node{int pc,dis;};
struct cmp{
	bool operator()(node a,node b){
		return a.dis>b.dis;
	}
};
priority_queue<node,vector<node>,cmp> p_q;
int n,m,k,u,v,w,c[MAXK],a[MAXK][MAXN],vis[MAXN],dis[MAXN],Ans1=LONG_LONG_MAX,ans;
int Flag[MAXK];
vector<node> edge[MAXN];

void Prim()
{
	for(int i=0;i<=n+k;i++) vis[i]=0,dis[i]=LONG_LONG_MAX;
	dis[1]=0;
	p_q=priority_queue<node,vector<node>,cmp>();
	p_q.push((node){1,0});
	while(!p_q.empty()){
		node nw=p_q.top(); p_q.pop();
		if(vis[nw.pc]) continue;
		vis[nw.pc]=1,ans+=nw.dis;
		
		int len=edge[nw.pc].size();
		for(int i=0;i<len;i++){
			int Npc=edge[nw.pc][i].pc,Ndis=edge[nw.pc][i].dis;
			if(vis[Npc]==0 && Ndis<dis[Npc]){
				dis[Npc]=Ndis;
				p_q.push((node){Npc,Ndis});
			}
		}
	}
	return ;
}

void dfs(int p)
{
	//cout<<"\t"<<p<<" "<<k<<endl;/////////////////////////////////////
	if(p>k){
		ans=0;
		for(int i=1;i<=k;i++){
			if(!Flag[i]) continue;
			ans+=c[i];
			for(int j=1;j<=n;j++) edge[j].push_back((node){n+i,a[i][j]});
		}
		Prim();
		Ans1=min(Ans1,ans);
		/**
		cout<<"    ";
		for(int i=1;i<=k;i++) cout<<Flag[i]<<" ";
		cout<<"    "<<ans<<endl;
		/**/
		for(int i=1;i<=k;i++){
			if(!Flag[i]) continue;
			for(int j=1;j<=n;j++) edge[j].pop_back();
		}
		return ;
	}
	Flag[p]=0;
	dfs(p+1);
	Flag[p]=1;
	dfs(p+1);
	return ;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=_r(),m=_r(),k=_r();
	for(int i=1;i<=m;i++){
		u=_r(),v=_r(),w=_r();
		edge[u].push_back((node){v,w});
		edge[v].push_back((node){u,w});
	}
	
	int flag=0,flag1;
	for(int i=1;i<=k;i++){
		c[i]=_r();
		if(c[i]) flag=1;
		flag1=0;
		for(int j=1;j<=n;j++){
			a[i][j]=_r();
			if(a[i][j]==0) flag1=1;
			edge[n+i].push_back((node){j,a[i][j]});
		}
		if(flag1==0) flag=1;
	}
	if(flag) dfs(1);
	else{
		for(int i=1;i<=k;i++){
			ans+=c[i];
			for(int j=1;j<=n;j++) edge[j].push_back((node){n+i,a[i][j]});
		}
		Prim();
		Ans1=ans;
	}
	_w(Ans1,'\n');
	
	return 0;
}
