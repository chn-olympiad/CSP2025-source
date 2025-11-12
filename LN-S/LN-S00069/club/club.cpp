#include<bits/stdc++.h>
using namespace std;
const int N=200010;
#define ll long long
ll n,a,b,c,T;
ll ans;
struct Node{
    ll ma,m,mi,a,b,c,id;
}t[N];
bool cmp(Node x,Node y){
    if(x.ma-x.m!=y.ma-y.m)return x.ma-x.m>y.ma-y.m;
    if(x.ma-x.mi!=y.ma-y.mi)return x.ma-x.mi>y.ma-y.mi;
    return x.ma>y.ma;
}
void ini(){
    ans=0;
    a=b=c=0;
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            t[i].id=i;
            scanf("%lld%lld%lld",&t[i].ma,&t[i].m,&t[i].mi);
            t[i].a=t[i].ma;
            t[i].b=t[i].m;
            t[i].c=t[i].mi;
            if(t[i].ma<t[i].m)swap(t[i].ma,t[i].m);
            if(t[i].ma<t[i].mi)swap(t[i].ma,t[i].mi);
            if(t[i].m<t[i].mi)swap(t[i].mi,t[i].m);
            if(t[i].ma==t[i].a&&t[i].m==t[i].b&&t[i].mi==t[i].c)t[i].a=1,t[i].b=2,t[i].c=3;
            else if(t[i].ma==t[i].a&&t[i].m==t[i].c&&t[i].mi==t[i].b)t[i].a=1,t[i].b=3,t[i].c=2;
            else if(t[i].ma==t[i].b&&t[i].m==t[i].a&&t[i].mi==t[i].c)t[i].a=2,t[i].b=1,t[i].c=3;
            else if(t[i].ma==t[i].b&&t[i].m==t[i].c&&t[i].mi==t[i].a)t[i].a=2,t[i].b=3,t[i].c=1;
            else if(t[i].ma==t[i].c&&t[i].m==t[i].a&&t[i].mi==t[i].b)t[i].a=3,t[i].b=1,t[i].c=2;
            else if(t[i].ma==t[i].c&&t[i].m==t[i].b&&t[i].mi==t[i].a)t[i].a=3,t[i].b=2,t[i].c=1;
        }
        sort(t+1,t+1+n,cmp);
  //      for(int i=1;i<=n;i++)cout<<t[i].id<<' '<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<" "<<t[i].ma<<" "<<t[i].m<<" "<<t[i].mi<<endl;
        for(int i=1;i<=n;i++){
            if(t[i].a==1&&a<n/2){a++,ans+=t[i].ma;}
            else if(t[i].a==2&&b<n/2){b++,ans+=t[i].ma;}
            else if(t[i].a==3&&c<n/2){c++,ans+=t[i].ma;}
            else if(t[i].b==1&&a<n/2){a++,ans+=t[i].m;}
            else if(t[i].b==2&&b<n/2){b++,ans+=t[i].m;}
            else if(t[i].b==3&&c<n/2){c++,ans+=t[i].m;}
            else if(t[i].c==1&&a<n/2){a++,ans+=t[i].mi;}
            else if(t[i].c==2&&b<n/2){b++,ans+=t[i].mi;}
            else {c++,ans+=t[i].mi;}
  //          cout<<ans<<' '<<a<<' '<<b<<' '<<c<<endl;
        }
        printf("%lld\n",ans);
        ini();
    }
    return 0;
}
