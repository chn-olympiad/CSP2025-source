#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct myd{
    int a,b,c,s0;
}d[100005];
int a,b,c,ans;
bool a1=true,b1=true,c1=true;
bool cmp(myd e,myd f){
    if(e.s0!=f.s0) return e.s0>f.s0;
    else if(e.a!=f.a)return e.a>f.a;
    else if(e.b!=f.b)return e.b>f.b;
    else return e.c>f.c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d[i].a>>d[i].b>>d[i].c;
            if(!d[i].a)d[i].s0++;
            if(!d[i].b)d[i].s0++;
            if(!d[i].c)d[i].s0++;
        }
        sort(d+1,d+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a==n/2) a1=false;
            if(b==n/2) b1=false;
            if(c==n/2) c1=false;
            int maxn=0;
            bool flag=false;
            maxn=max(d[i].a,max(d[i].b,d[i].c));
            if(maxn==d[i].a&&a1){
                ans+=d[i].a;
                a++;
                flag=true;
            }
            else if((maxn==d[i].b||(!flag&&maxn==d[i].a))&&b1){
                ans+=d[i].b;
                b++;
            }
            else{
                ans+=d[i].c;
                c++;
            }
            d[i].s0=0;
        }
        cout<<ans<<'\n';
        ans=0;
        a=0;
        b=0;
        c=0;
        a1=true;
        b1=true;
        c1=true;
    }
    return 0;
}

