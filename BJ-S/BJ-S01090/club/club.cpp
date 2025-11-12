#include<bits/stdc++.h>
using namespace std;
int t,n,ans,mp[5];
struct node{
    int a,b,c;
}a[114514];
bool cmp(node x,node y){
    int xbig,xmid,xsml;
    xbig=max(x.a,max(x.b,x.c));
    xsml=min(x.a,min(x.b,x.c));
    if(x.a==xbig&&x.b==xsml||x.b==xbig&&x.a==xsml)xmid=x.c;
    if(x.a==xbig&&x.c==xsml||x.c==xbig&&x.a==xsml)xmid=x.b;
    if(x.b==xbig&&x.c==xsml||x.c==xbig&&x.b==xsml)xmid=x.a;
    int ybig,ymid,ysml;
    ybig=max(y.a,max(y.b,y.c));
    ysml=min(y.a,min(y.b,y.c));
    if(y.a==ybig&&y.b==ysml||y.b==ybig&&y.a==ysml)ymid=y.c;
    if(y.a==ybig&&y.c==ysml||y.c==ybig&&y.a==ysml)ymid=y.b;
    if(y.b==ybig&&y.c==ysml||y.c==ybig&&y.b==ysml)ymid=y.a;
    return xbig>ybig||xbig==ybig&&xmid>ymid||xbig==ybig&&xmid==ymid&&xsml>ysml;
}
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n),mp[1]=mp[2]=mp[3]=0,ans=0;
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            auto x=a[i];
            int xbig,xmid,xsml;
            xbig=max(x.a,max(x.b,x.c));
            xsml=min(x.a,min(x.b,x.c));
            if(x.a==xbig&&x.b==xsml||x.b==xbig&&x.a==xsml)xmid=x.c;
            if(x.a==xbig&&x.c==xsml||x.c==xbig&&x.a==xsml)xmid=x.b;
            if(x.b==xbig&&x.c==xsml||x.c==xbig&&x.b==xsml)xmid=x.a;
            if(x.a==xbig&&mp[1]<n/2)mp[1]++,ans+=x.a;
            else if(x.b==xbig&&mp[2]<n/2)mp[2]++,ans+=x.b;
            else if(x.c==xbig&&mp[3]<n/2)mp[3]++,ans+=x.c;
            else if(x.a==xmid&&mp[1]<n/2)mp[1]++,ans+=x.a;
            else if(x.b==xmid&&mp[2]<n/2)mp[2]++,ans+=x.b;
            else if(x.c==xmid&&mp[3]<n/2)mp[3]++,ans+=x.c;
            else if(x.a==xsml&&mp[1]<n/2)mp[1]++,ans+=x.a;
            else if(x.b==xsml&&mp[2]<n/2)mp[2]++,ans+=x.b;
            else if(x.c==xsml&&mp[3]<n/2)mp[3]++,ans+=x.c;
        }
        cout<<ans<<'\n';
    }
}