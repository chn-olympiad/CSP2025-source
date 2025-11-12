#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,l,a[500009],c[500009],f[500009][5];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)c[i]=a[i]^c[i-1];
    if(a[1]==k)f[1][1]=1,f[1][2]=1;
    else f[1][1]=0,f[1][2]=0;
//    cout<<a[3]<<" "<<k<<endl;
    for(i=2;i<=n;i++){
        if(a[i]==k){
//            cout<<i<<" ok\n";
            f[i][1]=f[i-1][1]+1;
            f[i][2]=i;
            continue;
//            cout<<"?\n";
        }
        f[i][1]=f[i-1][1];
        f[i][2]=f[i-1][2];
        for(j=i-1;j>f[i-1][2];j--){
            if((c[i]^c[j-1])==k){
//                cout<<(c[i]^c[j-1])<<" "<<k<<" "<<c[i]<<" "<<c[j-1]<<" "<<i<<" "<<j<<" ok1\n";
                if(f[j][1]+1>f[i][1]){
//                    cout<<i<<" "<<j<<" ok2\n";
                    f[i][1]=f[j][1]+1;
                    f[i][2]=i;
                }
            }
        }
    }
    cout<<f[n][1];
    return 0;
}
