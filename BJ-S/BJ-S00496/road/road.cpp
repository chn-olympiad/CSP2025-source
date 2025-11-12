#include<bits/stdc++.h>
using namespace std;
const int N=1E4+10;
struct node{
    int x,y,z;
    int t;
}a[1000010];
int c[N];
int e[N];
int tot;
int fa[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node n1,node n2){
    return n1.z<n2.z;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)scanf("%d",&e[j]);
    }
    sort(a+1,a+m+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int fx=find(a[i].x);
        int fy=find(a[i].y);
        if(fx!=fy){
            fa[fx]=fy;
            ans+=a[i].z;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
