#include<bits/stdc++.h>
#define f for
using namespace std;
const int mn=5e3+5;
const long long aln=mn*mn,z=998244353;
int n,a[mn];
long long rcd[mn][mn][aln];
void input(){
    cin>>n;
    f(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
bool canbe(int mx,int tot){
    return tot/2>mx;
}
long long dfs(int dep,int mx,int tot){
    if(n-dep<3){
        rcd[dep][mx][tot]=0+1;
        return 0;
    }
    if(rcd[dep][mx][tot]){
        return rcd[dep][mx][tot]-1;
    }
    long long a1=dfs(dep+1,mx,tot);
    if(canbe(max(mx,a[dep]),tot+a[dep])){
        long long b1=dfs(dep+1,max(a[dep],mx),tot+a[dep]);
        a1=max(a1,b1);
    }
    rcd[dep][mx][tot]=(a1+1)%z;
    return a1%z;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    input();
    printf("%lld\n",dfs(0,0,0));
    return 0;
}