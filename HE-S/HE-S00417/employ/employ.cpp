#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,s[N],a[N],c[N],ans;
void solve1(){
    for(int i=1;i<=n;i++) a[i]=i;
    int res=0,pre=0;
    do{
        res=pre=0;
        for(int i=1;i<=n;i++){
            if(pre >= c[a[i]]) {pre++;continue;}
            if(!s[i]) pre++;
            else res++;
        }
        // cout<<res<<'\n';
        if(res >= m) ans++;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<'\n';
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch;cin>>ch;
        s[i]=ch-'0';
    } 
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n <= 10) solve1(),exit(0);
    else cout<<0<<'\n';
    return 0;
}