#include <bits/stdc++.h>
using namespace std;
const long long  mx=110000;
long long   n,m,b[mx],c,y=1,t,z;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) b[i]=0;
    for (int i=1; i<=n; i++){
        cin>>b[i];
    }
    for (int i=1; i<=n; i++){
        if(b[i]==m) t++;
    }
    cout<<t;
    return 0;
}
