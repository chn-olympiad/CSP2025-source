#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 107
int f[N][N];

inline void solve(){
    memset(f,0,sizeof f);
    int n,Ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        for(int j=n/2;~j;j--)
            for(int k=n/2;~k;k--){
                if(j+k>i||j+k<i-n/2) continue;
                if(j+k<i) f[j][k]+=z;
                if(j) f[j][k]=max(f[j][k],f[j-1][k]+x);
                if(k) f[j][k]=max(f[j][k],f[j][k-1]+y);
                if(i==n) Ans=max(Ans,f[j][k]);
            }
    }
    cout<<Ans<<'\n';
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}
/*
g++ -Wall club.cpp -o club
./club
*/