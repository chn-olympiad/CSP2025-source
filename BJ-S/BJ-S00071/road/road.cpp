#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,val;
}a[1000111];
bool cmp(node a,node b){
    return a.val<b.val;
}
int fas[100021];
int n,m,k;
int find(int x){
    if(fas[x]==x){
        return x;
    }
    return fas[x]=find(x);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        fas[i]=i;
        //cout<<fas[i]<<endl;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].val);
    }
    int tot=m;
    for(int i=1;i<=k;i++){
        int c;
        scanf("%d",&c);
        for(int j=1;j<=n;j++){
            a[++tot].u=j;
            a[tot].v=n+i;
            //cin>>a[tot].val;
            scanf("%d",&a[tot].val);
            //cout<<a[tot].u<<' '<<a[tot].v<<' '<<a[tot].val<<endl;
        }
    }
    m=tot;
    //cout<<m<<endl;
    sort(a+1,a+m+1,cmp);
    long long cnt=0,ans=0;;
    for(int i=1;i<=m;i++){
        if(cnt==n+k-1){
            break;
        }
        int xxx=find(a[i].u);
        int yyy=find(a[i].v);
        if(xxx==yyy){
            continue;
        }
        cnt++;
        ans+=a[i].val;
        //cout<<xxx<<' '<<yyy<<' '<<fas[xxx]<<endl;
        fas[yyy]=xxx;
    }
    cout<<ans;
    return 0;
}
