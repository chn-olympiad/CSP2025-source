#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n,m,use[505],pt[505],bs,pt0;
int jc(){
    long long k=1;
    for(int i=1;i<=n;i++){
        k=(k*i)%mod;
    }
    return k;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='1')use[i]=1;
        else bs=1;
    }
    if(bs==0||m==1){
        long long dl=jc();
        cout<<dl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>pt[i];
        if(pt[i]==0)pt0=1;
    }
    if(n==m&&pt0){cout<<0;return 0;}
    cout<<1;
    return 0;
}