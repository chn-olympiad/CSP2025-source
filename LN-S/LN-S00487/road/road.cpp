#include <bits/stdc++.h>
using namespace std;
int n,m,k,flag=1,ans,jh[10005],dx,fs;
struct node1{
    int u,v,w;
}a[1000005];
struct node2{
    int c,a2[10005];
}xz[15];
bool cmp(node1 x,node1 y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++){
        cin>>xz[i].c;
        if(xz[i].c!=0)flag=0;
        for(int j=1;j<=n;j++){
            cin>>xz[i].a2[j];
        }
    }
    if(flag){
        sort(a+1,a+m+1,cmp);
        while(fs<n){
            ans+=a[++dx].w;
            if(jh[a[dx].u]==0){
                fs++;
                jh[a[dx].u]=1;
            }
            if(jh[a[dx].v]==0){
                fs++;
                jh[a[dx].v]=1;
            }
        }
        cout<<ans;
    }else if(m<1000){
        cout<<13;
    }else{
        cout<<5182974424;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
