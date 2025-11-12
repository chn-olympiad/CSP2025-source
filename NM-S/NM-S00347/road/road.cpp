#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,add=0;
    n=m=k=0;
    cin>>n>>m>>k;
    int as[m+2];
    int as1[m+2];
    int as2[m+2];
    int bs[k+2][n+2];
    for(int i=0;i<m;i++){
        cin>>as[i];
        cin>>as1[i];
        cin>>as2[i];
    }
    for(int j=0;j<k;j++){
        for(int i=0;i<=n;i++){
        cin>>bs[j][i];
    }
    }
    for(int i=0;i<m;i++){
        add+=as2[i];
    }
    cout<<add;
    return 0;
}
