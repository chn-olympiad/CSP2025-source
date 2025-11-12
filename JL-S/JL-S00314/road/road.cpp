#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000000],b[1000000],c[10000];
int main(){
    freopen("road.in","w",stdin);
    freopen("road.out","r",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    cout<<n*m-k;

    return 0;
}

