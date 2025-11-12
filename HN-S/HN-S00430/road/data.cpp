#include <bits/stdc++.h>
using namespace std;
#define int long long
int n=10000,m=1000000,k=10;
mt19937 rnd(time(0));
signed main(){
    freopen("1.in","w",stdout);
    cout<<n<<' '<<m<<' '<<k<<'\n';
    for(int x=1;x<=m;x++){
        int u=rnd()%n+1,w=rnd()%n+1,val=1000000000;
        cout<<u<<' '<<w<<' '<<val<<'\n';
    }
    for(int x=1;x<=k;x++){
        cout<<rnd()%1000000<<' ';
        for(int y=1;y<=n;y++){
            cout<<100000000<<' ';
        }
        cout<<'\n';
    }
}