#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    long long x=0,w=0;
    char c=0;
    while(c<'0'||c>'9'){
        w|=c=='-';
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return w?-x:x;
}
const long long INF=1e18;
int n,m,k;
struct edge{
    int u,v,w;
    friend bool operator <(const edge&a,const edge&b){
        return a.w<b.w;
    }
}e[2000050],e2[1000050];
int a[10][10050],c[10];
long long ans=INF;
int f[10050],cnt;
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
long long res;
inline void Kru(int n,int m){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(e+1,e+m+1);
    for(int i=1,A,B;i<=m;i++){
        A=find(e[i].u);
        B=find(e[i].v);
        if(A==B){
            continue;
        }
        res+=e[i].w;
        f[A]=B;
    }
    ans=min(ans,res);
}
int main(){
     freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++){
		e2[i].u=read();
		e2[i].v=read();
		e2[i].w=read();
	}
    for(int i=0;i<k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
			a[i][j]=read();
        }
    }
    sort(e2+1,e2+m+1);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(e+1,e+m+1);
    for(int i=1,A,B;i<=m;i++){
        A=find(e2[i].u);
        B=find(e2[i].v);
        if(A==B){
            continue;
        }
        e2[++cnt]=e2[i];
        f[A]=B;
    }
    m=cnt;
    for(int S=0,cntn,cntm;S<(1<<k);S++){
        cntn=n;
        cntm=m;
        res=0;
        for(int i=1;i<=m;i++){
        	e[i]=e2[i];
		}
        for(int j=0;j<k;j++){
            if((1<<j)&S){
                cntn++;
                res+=c[j];
                for(int i=1;i<=n;i++){
                    e[++cntm]={cntn,i,a[j][i]};
                }
            }
        }
        Kru(cntn,cntm);
    }
    printf("%lld",ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
