#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
struct Thing{
    ll a1,a2,a3;
}a[N];
vector<Thing> v1,v2,v3;
ll T,n,ans;
bool cmp1(const Thing &x,const Thing &y){
    ll MX1=x.a1-x.a2,MX2=x.a1-x.a3,MY1=y.a1-y.a2,MY2=y.a1-y.a3;
    if(MX1-MY1<MX2-MY2) return MX2>MY2;
    else if(MX1-MY1==MX2-MY2) return x.a2<y.a2;
    else return MX1>MY1;
}
bool cmp2(const Thing &x,const Thing &y){
    ll MX1=x.a2-x.a3,MX2=x.a2-x.a1,MY1=y.a2-y.a3,MY2=y.a2-y.a1;
    if(MX1-MY1<MX2-MY2) return MX2>MY2;
    else if(MX1-MY1==MX2-MY2) return x.a3<y.a3;
    else return MX1>MY1;
}
bool cmp3(const Thing &x,const Thing &y){
    ll MX1=x.a3-x.a2,MX2=x.a3-x.a1,MY1=y.a3-y.a2,MY2=y.a3-y.a1;
    if(MX1-MY1<MX2-MY2) return MX2>MY2;
    else if(MX1-MY1==MX2-MY2) return x.a1<y.a1;
    else return MX1>MY1;
}
bool cmp11(const Thing &x,const Thing &y){return x.a1>y.a1;}
bool cmp22(const Thing &x,const Thing &y){return x.a2>y.a2;}
bool cmp33(const Thing &x,const Thing &y){return x.a3>y.a3;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        ans=0;
        v1.clear();
        v2.clear();
        v3.clear();
        scanf("%lld",&n);
        for(ll i=1,aa1,aa2,aa3;i<=n;i++){
            scanf("%lld%lld%lld",&aa1,&aa2,&aa3);
            if(aa1>=aa2&&aa1>=aa3) v1.push_back({aa1,aa2,aa3});
            else if(aa2>aa1&&aa2>aa3) v2.push_back({aa1,aa2,aa3});
            else if(aa3>aa1&&aa3>aa2) v3.push_back({aa1,aa2,aa3});
        }
        while(v1.size()>n/2||v2.size()>n/2||v3.size()>n/2){
            sort(v1.begin(),v1.end(),cmp11);
            sort(v2.begin(),v2.end(),cmp22);
            sort(v3.begin(),v3.end(),cmp33);
            if(v1.size()>n/2){
                ll A1,A2,A3;
                sort(v1.begin(),v1.end(),cmp1);
                while(v1.size()>n/2){
                    A1=v1.back().a1,A2=v1.back().a2,A3=v1.back().a3;
                    if(A1-A2<=A1-A3) v2.push_back(v1.back());
                    else v3.push_back(v1.back());
                    v1.pop_back();
                }
            }
            if(v2.size()>n/2){
                ll A1,A2,A3;
                sort(v2.begin(),v2.end(),cmp2);
                while(v2.size()>n/2){
                    A1=v2.back().a1,A2=v2.back().a2,A3=v2.back().a3;
                    if(A2-A3<A2-A1) v3.push_back(v2.back());
                    else v1.push_back(v2.back());
                    v2.pop_back();
                }
            }
            if(v3.size()>n/2){
                ll A1,A2,A3;
                sort(v3.begin(),v3.end(),cmp3);
                while(v3.size()>n/2){
                    A1=v3.back().a1,A2=v3.back().a2,A3=v3.back().a3;
                    if(A3-A1<=A3-A2) v1.push_back(v3.back());
                    else v2.push_back(v3.back());
                    v3.pop_back();
                }
            }
        }
        for(ll i=0;i<v1.size();i++) ans+=v1[i].a1;
        for(ll i=0;i<v2.size();i++) ans+=v2[i].a2;
        for(ll i=0;i<v3.size();i++) ans+=v3[i].a3;
        printf("%lld\n",ans);
    }
    return 0;
}
