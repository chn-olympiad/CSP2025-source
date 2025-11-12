#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n,a[5001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
