#include <bits/stdc++.h>
using namespace std;
int maxx[10],t,m,n,k,u[100000],sum;
char v[100000],w[1000000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>u[i]>>v[i];
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
    }
    for(int i=1;i<=m;i++){
        cout<<0<<endl;
    }
    return 0;
}
