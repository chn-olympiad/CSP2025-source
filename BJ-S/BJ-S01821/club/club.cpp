#include<bits/stdc++.h>
using namespace std;
int a[100005][4],n,t,cnt[100005],p[4],tot;
struct node{
    int a[2];
}c[100005];
bool cmp(node a,node b){
    return a.a[0]<b.a[0];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(a[i][j]>a[i][cnt[i]]) cnt[i]=j;
            }
        }
        for(int i=1;i<=n;i++) p[cnt[i]]++;
        int nd=0,ans=0;
        tot=0;
        for(int i=1;i<=3;i++)
            if(p[i]>n/2) nd=i;
        for(int i=1;i<=n;i++){
            ans+=a[i][cnt[i]];
            if(cnt[i]==nd){
                tot++;
                memset(c[tot].a,0,sizeof(c[tot].a));
                for(int j=1;j<=3;j++)
                    if(j!=cnt[i]){
                        if(!c[tot].a[0]) c[tot].a[0]=a[i][cnt[i]]-a[i][j];
                        else c[tot].a[1]=a[i][cnt[i]]-a[i][j];
                    }
                if(c[tot].a[0]>c[tot].a[1])
                    swap(c[tot].a[0],c[tot].a[1]);
            }
        }
        sort(c+1,c+tot+1,cmp);
        for(int i=1;i<=tot;i++)
            if(i<=tot-n/2) ans-=c[i].a[0];
        cout<<ans<<endl;
    }
}
