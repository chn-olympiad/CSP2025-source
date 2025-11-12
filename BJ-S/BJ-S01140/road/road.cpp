#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,city[10100];//k==0,n,cheng liang,m,lu liang
struct road{
    int u,v,w;
}a[1000100];
bool cmp(road a,road b){
    return a.w<b.w;
}
int fa(int x){
    if(city[x]==x)return x;
    city[x]=fa(city[x]);
    return city[x];
}
int isl(){
    for(int i=1;i<m;i++){
        if(fa(i)!=fa(i+1))return 0;
    }
    return 1;
}
int ui(int a,int b){
    int c=fa(a),d=fa(b);
    city[c]=d;
    return 0;
}
int main()
{
    //tuo bu pai xu
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i=1;i<=n;i++)city[i]=i;
    sort(a+1,a+m+1,cmp);
    for(int i=1;;i++){
        if(i>=n-1&&isl()==1)break;
        if(fa(a[i].u)!=fa(a[i].v)){
            ans+=a[i].w;
            ui(a[i].u,a[i].v);
        }
    }
    cout<<ans;
    return 0;
}
