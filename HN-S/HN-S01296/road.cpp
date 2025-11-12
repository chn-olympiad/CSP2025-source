#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[2000005];
int find(int x){
    if(f[x]==x){
        return x;
    }
    return f[x]=find(f[x]);
}
void f_merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    f[x]=y;
}
struct node{
    int u,v,w;
}A[2000005],B[2000005],D[2000005];
bool cmp(node aa,node bb){
    return aa.w<bb.w;
}
int bian[14][20005],C[14];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        for(int i=1;i<=m;i++){
            A[i].u=A[i].v=A[i].w=0;
        }
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            A[i].u=u;
            A[i].v=v;
            A[i].w=w;
        }
        for(int i=1;i<=k;i++){
            cin>>C[i];
            for(int j=1;j<=n;j++){
                cin>>bian[i][j];
            }
        }
        sort(A+1,A+m+1,cmp);
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(find(A[i].u)!=find(A[i].v)){
                f_merge(A[i].u,A[i].v);
                cnt++;
                B[cnt].u=A[i].u;
                B[cnt].v=A[i].v;
                B[cnt].w=A[i].w;
            }
        }
        int Daan=1e18;
        for(int zhuang=0;zhuang<(1<<k);zhuang++){
            int ccnt=cnt;
            for(int j=1;j<=ccnt;j++){
                D[j].u=B[j].u;
                D[j].v=B[j].v;
                D[j].w=B[j].w;
            }
            int Ans=0;
            for(int j=1;j<=k;j++){
                if((zhuang&(1<<j-1))>0){
                    for(int id=1;id<=n;id++){
                        ccnt++;
                        D[ccnt].u=j+n;
                        D[ccnt].v=id;
                        D[ccnt].w=bian[j][id];
                    }
                    Ans+=C[j];
                }
            }
            sort(D+1,D+ccnt+1,cmp);
            for(int j=1;j<=n+k;j++){
                f[j]=j;
            }
            for(int j=1;j<=ccnt;j++){
                if(find(D[j].u)!=find(D[j].v)){
                    f_merge(D[j].u,D[j].v);
                    Ans+=D[j].w;
                }
            }
            Daan=min(Daan,Ans);
        }
        cout<<Daan<<'\n';
    return 0;
}