#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,shu[5005];cin>>n;
    for(int i=1;i<=n;i++) cin>>shu[i];
    if(n<3)cout<<0;
    else if(shu[1]+shu[2]+shu[3] > 2*max(max(shu[1],shu[2]),shu[3]))cout<<1;
    else cout<<0;
    return 0;

}
