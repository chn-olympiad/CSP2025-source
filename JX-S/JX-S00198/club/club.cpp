#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt1,cnt2,cnt3,t;
struct node{
    int a;
    int b;
    int c;

    int ma;
    int fi;
    int sa;
    int se;
    int ta;
    int ti;
}nd[100010];
bool cmp(node x,node y){
    if(x.fi!=y.fi) return x.fi<y.fi;
    if(x.ma!=y.ma) return x.ma>y.ma;
    if(x.sa!=y.sa) return x.sa>y.sa;
    return x.ta>y.ta;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cnt1=0,cnt2=0,cnt3=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>nd[i].a>>nd[i].b>>nd[i].c;
            nd[i].ma=max(nd[i].a,max(nd[i].b,nd[i].c));
            nd[i].ta=max(nd[i].a,max(nd[i].b,nd[i].c));
            if(nd[i].ma==nd[i].a){
                nd[i].fi=1;
                if(nd[i].ta==nd[i].b) nd[i].ti=2,nd[i].se=3,nd[i].sa=nd[i].c;
                else nd[i].ti=3,nd[i].se=2,nd[i].sa=nd[i].b;
            }
            else if(nd[i].ma==nd[i].b){
                nd[i].fi=2;
                if(nd[i].ta==nd[i].a) nd[i].ti=1,nd[i].se=3,nd[i].sa=nd[i].c;
                else nd[i].ti=3,nd[i].se=1,nd[i].sa=nd[i].a;
            }
            else{
                nd[i].fi=3;
                if(nd[i].ta==nd[i].a) nd[i].ti=1,nd[i].se=2,nd[i].sa=nd[i].b;
                else nd[i].ti=2,nd[i].se=1,nd[i].sa=nd[i].a;
            }
        }
        sort(nd+1,nd+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(nd[i].fi==1&&cnt1<n/2) ans+=nd[i].ma,cnt1++;
            else if(nd[i].fi==2&&cnt2<n/2) ans+=nd[i].ma,cnt2++;
            else if(nd[i].fi==3&&cnt3<n/2) ans+=nd[i].ma,cnt3++;
            else{
                if(nd[i].se==1&&cnt1<n/2) ans+=nd[i].sa,cnt1++;
                else if(nd[i].se==2&&cnt2<n/2) ans+=nd[i].sa,cnt2++;
                else if(nd[i].se==3&&cnt3<n/2) ans+=nd[i].sa,cnt3++;
                else{
                    if(nd[i].ti==1&&cnt1<n/2) ans+=nd[i].ta,cnt1++;
                    else if(nd[i].ti==2&&cnt2<n/2) ans+=nd[i].ta,cnt2++;
                    else if(nd[i].ti==3&&cnt3<n/2) ans+=nd[i].ta,cnt3++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
