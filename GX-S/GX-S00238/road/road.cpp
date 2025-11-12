#include<bits/stdc++.h>
using namespace std;
long long vk[13][10090],fa[10090];
int num=0,num2=1;
struct node{
    int a,b;
    long long v;
}q[55000000];
bool cmp(node x,node y){
    return x.v<y.v;
}
int find(int x){
    if(fa[x]==x)return x;
    else return find(fa[x]);
}
void contest(int x,int y){
    fa[find(x)]=find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long miv,ans=0;
    int n,m,k,x,y;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        num++;
        cin>>q[num].a>>q[num].b>>q[num].v;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>vk[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            num++;
            miv=998244353;
            for(int o=1;o<=k;o++){
                miv=min(miv,vk[o][0]+vk[o][i]+vk[o][j]);
            }
            q[num].a=i,q[num].b=j,q[num].v=miv;
        }
    }
    sort(q+1,q+num+1,cmp);
    for(int i=1;i<=num;i++){
        x=q[i].a,y=q[i].b;
        fa[x]=find(fa[x]),fa[y]=find(fa[y]);
        if(fa[x]!=fa[y]){
            contest(x,y);
            num2++;
            ans+=q[i].v;
        }
        if(num2==n)break;
    }
    cout<<ans;
    return 0;
}
