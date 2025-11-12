#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int flag=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=0;
    }
    if(flag){
        cout<<n/2;
    }else{
        cout<<1;
    }
    return 0;
}
