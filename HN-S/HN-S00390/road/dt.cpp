#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main(){
    freopen("road.in","w",stdout);
    int n=1e4,m=1e6,k=10,V=1e9;
    cout<<n<<' '<<m<<' '<<k<<'\n';
    for(int i=1;i<n;i++) cout<<rnd()%i+1<<' '<<i+1<<' '<<rnd()%V+1<<'\n';
    for(int i=n;i<=m;i++) cout<<rnd()%n+1<<' '<<rnd()%n+1<<' '<<rnd()%V+1<<'\n';
    for(int i=1;i<=k;i++){
        cout<<rnd()%V+1<<' ';
        for(int j=1;j<=n;j++) cout<<rnd()%V+1<<' ';
        cout<<'\n';
    }
}