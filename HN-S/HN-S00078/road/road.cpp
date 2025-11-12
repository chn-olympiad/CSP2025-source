#include <bits/stdc++.h>
//#define int long long
using namespace std;

int read(){
	int x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
//多测清空
//不要把变量搞混，特别是i和j
//不要看错数据范围
//读题！
//对完样例要对拍
//时间不够了就老老实实打暴力吧
const int N=1e4+7;
int n,m,k;
typedef long long lglg;
//vector<int>G[N];
int fa[N];
int dsu(int u){
	return (u==fa[u])?u:fa[u]=dsu(fa[u]);
}
//int n,m,k;
struct edgez{
	int x,y,z;
	
}e[2000007];
edgez makenode(int xx,int yy,int zz){
		edgez res;
		res.x=xx;
		res.y=yy;
		res.z=zz;
		return res;
	}
edgez cpyz[2000007];
bool cmp(edgez A,edgez B){
	return A.z<B.z;
}
//T2……
//给你一个小时想一下吧 
//16:05停止 
//算了打暴力 
int c[19];
int cost[19][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//不要注释掉，不要打错文件名，测完大样例要改回来 
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i].x=read();e[i].y=read();e[i].z=read();
	}
	if(k<=5){
		long long ans=4e18;
		
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++){
				cost[i][j]=read();
			}
		}
		int cnt=m;
//		for(int i=1;i<=m;i++){
//			
//		}
		for(int i=0;i<(1<<k);i++){
			for(int j=1;j<=m;j++){
				cpyz[j]=e[j];
			}
			
			int popc=0;
			int cnct=0;
			long long res=0;
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					popc++;
					res+=c[j+1];
					for(int l=1;l<=n;l++){
						cpyz[++cnt]=makenode(n+j+1,l,cost[j+1][l]);
					}
				}
			}
			sort(cpyz+1,cpyz+1+cnt,cmp);
			for(int j=1;j<=n+popc;j++)	fa[j]=j;
			for(int j=1;j<=cnt;j++){
				int x=dsu(cpyz[j].x),y=dsu(cpyz[j].y),z=cpyz[j].z;
				if(x==y)	continue;
				res+=z;
				fa[x]=y;
				cnct++;
				if(cnct==n+popc-1)	break;
			}
			ans=min(ans,res); 
		}
		printf("%lld\n",ans);
	} 
	else{
		long long ans=0;
		int cnt=m;
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++){
				cost[i][j]=read();
				e[++cnt].x=j;
				e[cnt].y=n+i;
				e[cnt].z=cost[i][j];
			}
		}
		sort(e+1,e+1+cnt,cmp);
		for(int j=1;j<=n+k;j++)	fa[j]=j;
		int cnct=0;
		for(int j=1;j<=cnt;j++){
			int x=dsu(e[j].x),y=dsu(e[j].y),z=e[j].z;
			if(x==y)	continue;
			ans+=z;
			fa[x]=y;
			cnct++;
			if(cnct==n+k-1)	break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
竟然没有多测？
完了，只会72pts的暴力 
k很小（只有10）有啥用呢
 4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

By C_0_a4S
Luogu_uid=1424067
expect:72pts
*/


