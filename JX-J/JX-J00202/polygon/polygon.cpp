#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    int c=0;
    for(int i=3;i<=n;i++){
        if(b[i]>a[i]*2) c++;
    }
    cout<<c;
    return 0;
}
