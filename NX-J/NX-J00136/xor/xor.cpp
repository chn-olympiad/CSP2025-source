#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.cpp.in","r",stdin);
    freopen("xor.cpp.out","w",stdout);
    int n=0,k=0,q,m;
    cin>>n>>k;
    m=q;
    for(int i=1;i<=n;i++)
    {
        cin>>q;
        if(q>m)
        {
            m=q;
        }
        break;}
    cout<<m;
    return 0;
}
