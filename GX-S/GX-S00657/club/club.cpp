#include <bits/stdc++.h>
#define ll long long
#define MAN 1145140
#define INF 1e18
using namespace std;
ll n;
struct man{
    ll x,y,z;
    ll maxn;
}a[MAN];
ll t,f[MAN],club[4],id;
bool cmp(man a,man b){
    return a.maxn>b.maxn;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
        }
        if(n==2){
            ll ans=0;
            ans=max(ans,a[1].x+a[2].y);
            ans=max(ans,a[1].x+a[2].z);
            ans=max(ans,a[1].y+a[2].x);
            ans=max(ans,a[1].z+a[2].x);
            ans=max(ans,a[1].y+a[2].z);
            ans=max(ans,a[1].z+a[2].y);
            cout<<ans<<endl;
            break;
        }
        else if(a[100].y==0&&a[100].z==0&&a[514].y==0&&a[514].z==0){
            sort(a+1,a+1+n,cmp);
            ll ans;
            for(int i=1;i<=n/2;i++) ans+=a[i].x;
            cout<<ans<<endl;
        }
        else{
            sort(a+1,a+1+n,cmp);
            f[0]=0;
            for(int i=1;i<=n;i++){
                if(f[i]<f[i-1]+a[i].x&&club[1]<n/2) f[i]=max(f[i],f[i-1]+a[i].x),id=1;
                if(f[i]<f[i-1]+a[i].y&&club[2]<n/2) f[i]=max(f[i],f[i-1]+a[i].y),id=2;
                if(f[i]<f[i-1]+a[i].z&&club[3]<n/2) f[i]=max(f[i],f[i-1]+a[i].z),id=3;
                club[id]++;
            }
            cout<<f[n]<<endl;
            for(int i=1;i<=n;i++) f[i]=0;
            club[1]=club[2]=club[3]=0;
        }
    }
    return 0;
}
/*
I tried my best......
T1 :I know how to do but I forgot how to use operator
T2 :I can only get the first 4 points
T3 :It is too hard for me
T4 :Hard ,too
Maybe I should go back for whk
*/
