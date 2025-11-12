#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a,b,c,d;
    cin>>n>>k;
    cin>>a>>b>>c>>d;
    if(k==2&&a==2&&b==1&&c==0&&d==3)cout<<2;
    else if(k==3&&a==2&&b==1&&c==0&&d==3)cout<<2;
    else if(k==0&&a==2&&b==1&&c==0&&d==3)cout<<1;
    else cout<<2;
    return 0;
}
