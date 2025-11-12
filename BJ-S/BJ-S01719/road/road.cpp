#include<bits/stdc++.h>
using namespace std;
struct qwe{
    int u;
    int v;
    int w;
}a[1200005];
//struct ewq{
//    int wei;
//    int shu;
//}b[1000005];
int c[20005];
int d[12][11005];
int zu(int x){
    if (c[x]!=x){
        c[x]=zu(c[x]);
    }
    return c[x];
}
int cha(int x,int y){
    if (zu(x)==zu(y)) return 0;
    else return 1;
}
void bing(int x,int y){
    c[zu(x)]=c[zu(y)];
}
bool cmp(qwe x,qwe y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        if (i<=n+k) c[i]=i;
    }
    int i2=m+1;
    int f=0;
    for (int i=1;i<=k;i++){
        cin>>d[i][0];
        if (d[i][0]==0){
            for (int j=1;j<=n;j++){
                scanf("%d",&a[i2].w);
                a[i2].u=n+i;
                a[i2].v=j;
                i2++;
            }
        }
        else{
            for (int j=1;j<=n;j++){
                scanf("%d",&d[i][j]);
            }
            f++;
        }
    }
    k-=f;
    sort(a+1,a+i2,cmp);
    long long ans=0;
    int i1=1;
    for (int i=1;i<=n+k-1;i++){
        if (cha(a[i1].u,a[i1].v)){
            bing(a[i1].u,a[i1].v);
            ans+=a[i1].w;
        }
        else i--;
        i1++;
    }
    cout<<ans<<endl;
    return 0;
}