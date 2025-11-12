#include<bits/stdc++.h>
using namespace std;
struct she{
    long long f,df,p,l;
};
long long t,n,h1,h2,h3;
bool peo[100100];
vector<she>g;
bool cmp(she x,she y){
    if(x.df==y.df){
        return x.f>y.f;
    }
    return x.df>y.df;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long r1=0,r2=0,r3=0;
        cin>>n;
        fill(peo,peo+n+10,true);
        g.clear();
        for(int i=1;i<=n;i++){
            cin>>h1>>h2>>h3;
            she sh1,sh2,sh3;
            sh1.f=h1;
            sh1.p=sh2.p=sh3.p=i;
            sh1.l=1;
            sh2.f=h2;
            sh2.l=2;
            sh3.f=h3;
            sh3.l=3;
            long long mi=min(h1,min(h2,h3));
            h1-=mi;
            h2-=mi;
            h3-=mi;
            sh1.df=h1;
            sh2.df=h2;
            sh3.df=h3;
            g.push_back(sh1);
            g.push_back(sh2);
            g.push_back(sh3);
        }
        int l1=0,l2=0,l3=0,ans;
        ans=0;
        sort(g.begin(),g.end(),cmp);
        for(int i=0;i<g.size();i++){
            if(g[i].l==1){
                if(l1<n/2&&peo[g[i].p]){
                    l1++;
                    peo[g[i].p]=false;
                    ans=ans+g[i].f;
                }
            }
            if(g[i].l==2){
                if(l2<n/2&&peo[g[i].p]){
                    l2++;
                    ans=ans+g[i].f;
                    peo[g[i].p]=false;
                }
            }
            if(g[i].l==3){
                if(l3<n/2&&peo[g[i].p]){
                    l3++;
                    ans=ans+g[i].f;
                    peo[g[i].p]=false;
                }
            }
            if(l1+l2+l3>=n){
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
