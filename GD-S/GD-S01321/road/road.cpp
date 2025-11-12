#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=1e4+10,M=1e6+10,K=12;

int n,m,k;
int a[K][N];

struct edge{
    int u,v,w;
}e[M];
bool cmp(edge x,edge y){
    return x.w<y.w;
}

namespace sub1{
    int fa[N];
    int findfa(int x){
        return fa[x]==x?x:(fa[x]=findfa(fa[x]));
    }
    void MST(){
        for(int i=1;i<=n;i++) fa[i]=i;

        sort(e+1,e+m+1,cmp);

        LL sum=0;
        int cnt=0;
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            int p=findfa(u),q=findfa(v);
            if(p!=q){
                fa[p]=q;
                sum+=w;
                cnt++;
                if(cnt==n-1) break;
            }
        }

        printf("%lld\n",sum);
        return;
    }
};
/*
my1

3 2 0
1 3 7
1 2 8

ans:15

4 6 0
1 2 2
1 4 7
2 4 1
2 3 2
2 3 2
3 4 2

ans:5

4 6 0
1 2 1
1 2 2
1 3 3
1 4 4
3 4 1
2 3 0

ans:2

*/

int main(){
	freopen("road.in","r",stdin);
	// freopen("my1.in","r",stdin);
	freopen("road.out","w",stdout);
	
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[i]={u,v,w};
    }

    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++) scanf("%d",&a[i][j]);
    }

    if(k==0){
        sub1::MST();
        return 0;
    }
    else{
        sub1::MST();
        return 0;
    }
	return 0;
}