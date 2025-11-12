#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
struct node{
    ll id,a,b,c;
};
bool cmp1(node x,node y){
    return (x.a-max(x.b,x.c))<(y.a-max(y.b,y.c));
}
bool cmp2(node x,node y){
    return (x.b-max(x.a,x.c))<(y.b-max(y.a,y.c));
}
bool cmp3(node x,node y){
    return (x.c-max(x.a,x.b))<(y.c-max(y.b,y.a));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        vector<node> v1,v2,v3;
        ll n;
        cin>>n;
        ll tot1=0,tot2=0,tot3=0,maxl=n/2,ans=0;
        for(ll i=1;i<=n;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            if(x>=y&&x>=z){
                v1.push_back({i,x,y,z});
                ans+=x;
                tot1++;
            }
            else if(y>=x&&y>=z){
                v2.push_back({i,x,y,z});
                ans+=y;
                tot2++;
            }
            else{
                v3.push_back({i,x,y,z});
                ans+=z;
                tot3++;
            }
        }
        if(tot1>maxl){
            sort(v1.begin(),v1.end(),cmp1);
            for(int i=0;i<(tot1-maxl);i++){
                ans-=v1[i].a;
                if(v1[i].b>v1[i].c) ans+=v1[i].b;
                else ans+=v1[i].c;
            }
        }
        else if(tot2>maxl){
            sort(v2.begin(),v2.end(),cmp2);
            for(int i=0;i<(tot2-maxl);i++){
                ans-=v2[i].b;
                if(v2[i].a>v2[i].c) ans+=v2[i].a;
                else ans+=v2[i].c;
            }
        }
        else{
            sort(v3.begin(),v3.end(),cmp3);
            for(int i=0;i<(tot3-maxl);i++){
                ans-=v3[i].c;
                if(v3[i].b>v3[i].a) ans+=v3[i].b;
                else ans+=v3[i].a;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
