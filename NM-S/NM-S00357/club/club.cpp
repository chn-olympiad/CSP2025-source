#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
ll t,n,ans=0;
ll cnt1=0,cnt2=0,cnt3=0;
struct node{
    ll a,b,c;
}pl[maxn];
ll a1[maxn],a2[maxn],a3[maxn];
ll v[maxn];
ll szh[4];
void solve(ll num){
    sort(v+1,v+num+1);
    ll tot=num-n/2;
    for(int i=1;i<=tot;i++){
        ans-=v[i];
    }
}

queue<ll> q;


signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ans=0;
        cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&pl[i].a,&pl[i].b,&pl[i].c);
            if(pl[i].a>=pl[i].b&&pl[i].a>=pl[i].c){
                cnt1++;
                a1[cnt1]=i;
                ans+=pl[i].a;
            }else if(pl[i].b>=pl[i].c){
                cnt2++;
                a2[cnt2]=i;
                ans+=pl[i].b;
            }else{
                cnt3++;
                a3[cnt3]=i;
                ans+=pl[i].c;
            }
        }
        if(2*cnt1>n){
            for(int i=1;i<=cnt1;i++){
                ll dis=min((pl[a1[i]].a-pl[a1[i]].b),(pl[a1[i]].a-pl[a1[i]].c));
                v[i]=dis;
            }
            solve(cnt1);
        }else if(2*cnt2>n){
            for(int i=1;i<=cnt2;i++){
                ll dis=min((pl[a2[i]].b-pl[a2[i]].a),(pl[a2[i]].b-pl[a2[i]].c));
                v[i]=dis;
            }
            solve(cnt2);
        }else if(2*cnt3>n){
            for(int i=1;i<=cnt3;i++){
                ll dis=min((pl[a3[i]].c-pl[a3[i]].b),(pl[a3[i]].c-pl[a3[i]].a));
                v[i]=dis;
            }
            solve(cnt3);
        }
        q.push(ans);
    }
    while(!q.empty()){
        printf("%lld\n",q.front());
        q.pop();
    }
    return 0;
}
