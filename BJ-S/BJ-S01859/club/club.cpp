#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct c{
    ll a1,a2,a3;
}a[1100000];
ll t,n,ans,an,bn,cn,maxn,p1,p2,p3;
ll s[4][1100000],cnt1,cnt2,cnt3,v1,v2,v3,f1,f2,f3;
bool tmp(c a,c b){
    if(a.a1!=b.a1)return a.a1>b.a1;
    if(a.a2!=b.a2)return a.a2>b.a2;
    return a.a3>b.a3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    ll x;
    while(t--){
        for(int i=1;i<=n;i++){
            a[i].a1=0;
            a[i].a2=0;
            a[i].a3=0;
        }
        memset(s,0,sizeof(s));
        cin>>n;
        an=n/2;
        bn=n/2;
        cn=n/2;
        ans=0;
        cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        sort(a+1,a+n+1,tmp);
        for(int i=1;i<=n;i++){
            p1=0,p2=0,p3=0,v1=0,v2=0,v3=0;
            if(an>0)p1=a[i].a1;
            else{
                for(int j=1;j<=cnt1;j++){
                    x=max(a[s[1][j]].a2,a[s[1][j]].a3);
                    if(bn<=0)x=a[s[1][j]].a3;
                    if(cn<=0)x=a[s[1][j]].a2;
                    if(p1<a[i].a1-a[s[1][j]].a1+x){
                        p1=a[i].a1-a[s[1][j]].a1+x;
                        v1=j;
                        if(x==a[s[1][j]].a2)f1=2;
                        else f1=3;
                    }
                }
            }
            if(bn>0)p2=a[i].a2;
            else{
                for(int j=1;j<=cnt2;j++){
                    x=max(a[s[2][j]].a1,a[s[2][j]].a3);
                    if(an<=0)x=a[s[2][j]].a3;
                    if(cn<=0)x=a[s[2][j]].a1;
                    if(p2<a[i].a2-a[s[2][j]].a2+x){
                        p2=a[i].a2-a[s[2][j]].a2+x;
                        v2=j;
                        if(x==a[s[2][j]].a1)f2=1;
                        else f2=3;
                    }
                }
            }
            if(cn>0)p3=a[i].a3;
            else{
                for(int j=1;j<=cnt3;j++){
                    x=max(a[s[3][j]].a2,a[s[3][j]].a1);
                    if(bn<=0)x=a[s[3][j]].a1;
                    if(an<=0)x=a[s[3][j]].a2;
                    if(p3<a[i].a3-a[s[3][j]].a3+x){
                        p3=a[i].a3-a[s[3][j]].a3+x;
                        v3=j;
                        if(x==a[s[3][j]].a2)f3=2;
                        else f3=1;
                    }
                }
            }
            maxn=max(p1,max(p2,p3));
            if(maxn==p1){
                if(an>0){an--;cnt1++;s[1][cnt1]=i;}
                else{
                    if(f1==2){bn--;cnt2++;s[2][cnt2]=s[1][v1];}
                    else{cn--;cnt3++;s[3][cnt3]=s[1][v1];}
                    s[1][v1]=i;
                }
            }
            if(maxn==p2){
                if(bn>0){bn--;cnt2++;s[2][cnt2]=i;}
                else{
                    if(f2==1){an--;cnt1++;s[1][cnt1]=s[2][v2];}
                    else{cn--;cnt3++;s[3][cnt3]=s[2][v2];}
                    s[2][v2]=i;
                }
            }
            if(maxn==p3){
                if(cn>0){cn--;cnt3++;s[3][cnt3]=i;}
                else{
                    if(f3==1){an--;cnt1++;s[1][cnt1]=s[3][v3];}
                    else{bn--;cnt2++;s[2][cnt2]=s[3][v3];}
                    s[3][v3]=i;
                }
            }
            ans+=maxn;
        }
        cout<<ans<<endl;
    }
    return 0;
}
