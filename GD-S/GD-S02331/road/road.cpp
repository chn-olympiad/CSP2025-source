#include<bits/stdc++.h>
#define rd() read()
#define wt write
#define pc putchar
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-'){
				f=-1;
			}
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		return x*f;
	}
	inline void write(int x){
		if(x<0){
			x=-x;
			pc('-');
		}
		if(x>9){
			write(x/10);
			pc(x%10+'0');
		}
		else{
			pc(x+'0');
		}
		return ;
	}
}
using namespace IO;
namespace Main{
	const int N=1e4+7,M=1e6+7;
	int n,m,k;
	int cnt,res=0x3f3f3f3f;
	bool st[N];
	int dist[N];
	int h[N],e[M],ne[M],w[M],idx;
	inline void add(int a,int b,int c){
		e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
		return ;
	}
	inline int prim(){
		int ans=0;
		memset(dist,0x3f,sizeof dist);
		dist[1]=0;
		priority_queue<PII,vector<PII>,greater<PII>> q;
		q.push({0,1});
		while(!q.empty()){
			auto t=q.top();
			q.pop();
			int u=t.sec,cst=t.fir;
			if(st[u]){
				continue;
			}
			st[u]=1;
			++cnt;
			ans+=cst;
			for(int i=h[u];~i;i=ne[i]){
				int j=e[i];
				if(dist[j]>w[i]){
					dist[j]=w[i];
					q.push({w[i],j});
				}
			}
		}
		return ans;
	}
	struct Node{
		int a,b,c;
	}s[N];
	int cost[13],sp[N][13];
	inline void main(){
		n=rd(),m=rd(),k=rd();
		memset(h,-1,sizeof h);
		for(int i=1;i<=m;i++){
			int a=rd(),b=rd(),c=rd();
			s[i]={a,b,c};
			add(a,b,c),add(b,a,c);
		}
//		res=min(res,prim());
//		for(int i=1;i<=k;i++){
//			memset(h,-1,sizeof h);
//			idx=0;
//			cost[i]=rd();
//			for(int j=1;j<=n;j++){
//				sp[j][i]=rd();
//				add(n+i,j,sp[j][i]),add(j,n+i,sp[j][i]);
//			}
//			for(int i=1;i<=m;i++){
////				if(s[i].a==k||s[i].b==k){
////					continue;
////				}
//				int a=s[i].a,b=s[i].b,c=s[i].c;
//				add(a,b,c),add(b,a,c);
//			}
//			res=min(res,prim()+cost[i]);
//		}
		res=prim();
		if(!k){
			wt(res);
			return ;
		}
		else{
			pc('0');
		}
		return ;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Main::main();
	return 0;
}

