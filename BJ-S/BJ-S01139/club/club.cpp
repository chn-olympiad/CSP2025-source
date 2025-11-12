#include<bits/stdc++.h>
using namespace std;
int n,q,ans,ca,cb,cc;
struct node{
    int a,b,c;
}a[1000001];
int d2d(int x,int y,int z){
    return x+y+z-max(x,max(y,z))-min(x,min(y,z));
}
bool cmp(node x,node y){
    int xa=max(max(x.a,x.b),x.c),ya=max(max(y.a,y.b),y.c);
    int xb=d2d(x.a,x.b,x.c),yb=d2d(y.a,y.b,y.c);
    return xa-xb>ya-yb;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>q;
    while(q--){
        cin>>n;
        ans=ca=cb=cc=0;
        for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c)ca++,ans+=a[i].a;
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)cb++,ans+=a[i].b;
            else if(a[i].c>=a[i].a&&a[i].c>=a[i].b)cc++,ans+=a[i].c;
        }
        for(int i=n/2+1;i<=n;i++){
            if(ca>=n/2)a[i].a=-1e9;
            if(cb>=n/2)a[i].b=-1e9;
            if(cc>=n/2)a[i].c=-1e9;
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c)ca++,ans+=a[i].a;
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)cb++,ans+=a[i].b;
            else if(a[i].c>=a[i].a&&a[i].c>=a[i].b)cc++,ans+=a[i].c;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
