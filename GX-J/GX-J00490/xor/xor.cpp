#include<bits/stdc++.h>
using namespace std;
int main {
    freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
int a[256];
for(int i=1;i<=n;i++){
    cin>>a[i];


}
if(n=1){
    if(a[1]=k)
    {
        cout<<1;
        return 0;
    }else {
    cout<<0;
    return 0;
    }
}

return 0;
}
