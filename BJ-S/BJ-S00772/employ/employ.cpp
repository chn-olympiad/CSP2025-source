#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000000000000000ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep_(i,a,b) for(int i=(a);i<(b);i++)
#define per_(i,a,b) for(int i=(a);i>(b);i--)
#define N 11
int n,m,ans,s[N],c[N],p[N];
char ch;
void mian(int argt){
    cin>>n>>m;
    rep(i,1,n){
        cin>>ch;
        s[i]=ch-'0';
    }
    rep(i,1,n){
        cin>>c[i];
        p[i]=i;
    }
    do{
        int cnt=0;
        rep(i,1,n){
            if(!s[i]||cnt>=c[p[i]]){
                cnt++;
            }
        }
        if(cnt<=n-m){
            ans++;
        }
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T=1;
    //cin>>T;
    rep(i,1,T){
        mian(i);
    }
}
/*
1. File IO
2. Array Size
3. Time
4. Memory
*/
