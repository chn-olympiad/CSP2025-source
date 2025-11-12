#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int M=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ma=0;
    for(int i=1;i<=n;i++){
        if(a[i]>ma){
            ma=a[i];
        }
        s+=a[i];
    }
    int low=ma*2;
    if(n<3) cout<<0;
    else if(n==3){
        if(s>low) cout<<1;
        else cout<<0;
    }
    return 0;
}
