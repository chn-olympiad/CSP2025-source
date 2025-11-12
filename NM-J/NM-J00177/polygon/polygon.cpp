#include<bits/stdc++.h>
using namespace std;
int n, ans;
int a[20];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    if((a[0]+a[1]>a[2])||(a[1]+a[2]>a[0])||(a[0]+a[2]>a[1])){
        ans=1;
        cout<<ans;
    }
    else{
            ans=0;
        cout<<ans;
    }
    return 0;
}
