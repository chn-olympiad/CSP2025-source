//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int maxx=-1;
    if(n<3){
        cout<<0%998244353;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]>maxx){
                maxx=a[i];
            }
        }
        if(sum>maxx*2){
            cout<<1%998244353;
        }
        else{
            cout<<0%998244353;
        }
    }
    return 0;
}
