#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],p[15][100005],maxn,minn,fa[100005],flag[15];
struct T{
    int u,v,w;
}a[2000005],b[2000005];
inline bool cmp(T x,T y){
    return x.w<y.w;
}
inline int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
inline int kruskal(int len,int now){
    //cout<<len<<" "<<now<<endl;
    int cnt=0;
    for(int i=1;i<=len;i++){
        b[i]=a[i];
    }
    for(int i=1;i<=now;i++){
        fa[i]=i;
    }
    sort(b+1,b+len+1,cmp);
    for(int i=1;i<=len;i++){
        int u=b[i].u,v=b[i].v,w=b[i].w;
        if(find(u)!=find(v)){
            fa[find(u)]=find(v);
            cnt+=w;
        }
    }
    return cnt;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    int len1=m,now1=n;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        now1++;
        for(int j=1;j<=n;j++){
            cin>>p[i][j];
            if(p[i][j]==0)flag[i]=1;
            len1++;
            a[len1]=T{now1,j,p[i][j]};
        }
    }
    minn=kruskal(len1,now1);
    int n1=n,k1=0;
    for(int i=1;i<=k;i++){
        if(c[i]==0&&flag[i]){
            n1++;
            for(int j=1;j<=n;j++){
                m++;
                a[m]=T{n1,j,p[i][j]};
            }
        }else{
            for(int j=1;j<=n;j++){
                p[k1][j]=p[i][j];
            }
            c[k1]=c[i];
        }
    }
    n=n1;
    k=k1;
    maxn=kruskal(m,n);
    for(int i=1;i<=(1<<k)-1;i++){
        int cnt=0,h=i,now=n,len=m,res=0;
        while(h){
            cnt++;
            if(h&1){
                now++;
                res+=c[cnt];
                if(res+minn>=maxn)break;
                for(int j=1;j<=n;j++){
                    len++;
                    a[len]=T{now,j,p[cnt][j]};
                }
                
            }
            h>>=1;
        }
        //cout<<maxn<<endl;
        maxn=min(maxn,kruskal(len,now)+res);
        //cout<<maxn<<" "<<res<<endl;
    }
    cout<<maxn;
    return 0;
}//g++ -Wall -std=c++14 -fsanitize=address,undefined,leak -O2 2.cpp -o 2
//time ./2
//17:49