#include<bits/stdc++.h>
using namespace std;
int n,sum=0,a;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    a=n;
    for(int i=1;i<=n;i++){
        sum+=a;
        a--;
    }
    cout<<sum%998%244%353;
    return 0;
}
