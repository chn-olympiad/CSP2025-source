#include<bits/stdc++.h>
using namespace std;
// int lowbit(int x){return x&-x;}
// void add(int x,int d){
//     for(;x<=n;x+=lowbit(x)) tree[x]+=d;
// }
// void sum(int x){
//     int ret=0;
//     for(;x;x-=lowbit(x)) ret+=tree[x];
//     return ret;
// }
const int N=1e5+10;
int T,n,a[N],b[N],c[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n;
        int jsa=0,jsb=0,jsc=0,A[N],B[N],C[N];
        for(int i=1;i<=n;i++) A[i]=0,B[i]=0,C[i]=0;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i],ans+=max({a[i],b[i],c[i]});
        for(int i=1;i<=n;i++){
            if(a[i]>=b[i]&&a[i]>=c[i]) A[++jsa]=min(a[i]-b[i],a[i]-c[i]);
            else if(b[i]>=a[i]&&b[i]>=c[i]) B[++jsb]=min(b[i]-a[i],b[i]-c[i]);
            else if(c[i]>=a[i]&&c[i]>=b[i]) C[++jsc]=min(c[i]-a[i],c[i]-b[i]);
        }
        if(jsa>n/2){
            sort(A+1,A+jsa+1);
            jsa-=n/2;
            for(int i=1;i<=jsa;i++) ans-=A[i];
        }
        // for(int i=1;i<=jsa;i++) cout<<A[i]<<' ';
        // cout<<'\n';
        else if(jsb>n/2){
            sort(B+1,B+jsb+1);
            jsb-=n/2;
            for(int i=1;i<=jsb;i++) ans-=B[i];
        }
        else if(jsc>n/2){
            sort(C+1,C+jsc+1);
            jsc-=n/2;
            for(int i=1;i<=jsc;i++) ans-=C[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}