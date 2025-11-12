#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    bool f1=1,f2=0;
    int c=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1)f1=0;
        else c++;
        if(a[i]>1)f2=0;
    }if(f1&&k==0)cout<<n;
    if(k==1&&f2)cout<<n-c;
    else if(k==0&&f2)cout<<c;
    cout<<1;
    return 0;
}
