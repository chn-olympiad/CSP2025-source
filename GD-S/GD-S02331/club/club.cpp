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
	const int N=1e5+7;
	int T,n,res;
	bool st[N];
	int res1,res2,res3;
	int cnta,cntb,cntc;
	int a[N],b[N],c[N],d[N];
	inline void dfs(int u,int ans,int cnta,int cntb,int cntc){
		bool f1=(cnta==n/2),f2=cntb==n/2,f3=cntc==n/2;
		if(u==n+1){
			res=max(res,ans);
			return ;
		}
		if(ans+d[n]-d[u-1]<=res){
			return ;
		}
		if(!f1){
			dfs(u+1,ans+a[u],cnta+1,cntb,cntc);
		}
		if(!f2){
			dfs(u+1,ans+b[u],cnta,cntb+1,cntc);
		}
		if(!f3){
			dfs(u+1,ans+c[u],cnta,cntb,cntc+1);
		}
		return ;
	}
	inline void dfstb(int u,int ans,int cnta,int cntb){
		bool f1=(cnta==n/2),f2=cntb==n/2;
		if(u==n+1){
			res=max(res,ans);
			return ;
		}
		if(!f1){
			dfstb(u+1,ans+a[u],cnta+1,cntb);
		}
		if(!f2){
			dfstb(u+1,ans+b[u],cnta,cntb+1);
		}
		return ;
	}
	inline void main(){
		T=rd();
		while(T--){
			n=rd();
			res=0;
			memset(d,0,sizeof d);
			bool ta=1,tb=1;
			priority_queue<int,vector<int>,less<int>> q;
			for(int i=1;i<=n;i++){
				a[i]=rd(),b[i]=rd(),c[i]=rd();
				q.push(a[i]);
				if(b[i]!=0||c[i]!=0){
					ta=0;
				}
				if(c[i]!=0){
					tb=0;
				}
				d[i]=d[i-1]+max(a[i],max(b[i],c[i]));
			}
			if(ta){
				for(int i=1;i<=n/2;i++){
					res+=q.top();
					q.pop();
				}
				wt(res),pc('\n');
			}
			else if(tb){
				dfstb(1,0,0,0);
				wt(res),pc('\n');
			}
			else{
				dfs(1,0,0,0,0);
				wt(res),pc('\n');
			}
		}
		return ;
	} 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Main::main();
	return 0; 
} 
