#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,l=0;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,c,v;
        cin>>x>>c>>v;
        l+=v;
    }cout<<l;
    return 0;
}
