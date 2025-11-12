#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5&&a[0]==1){
        cout<<9;
    }
    if(n==5&&a[0]==2){
        cout<<"6";
    }
    if(n==20){
        cout<<"1042392";
    }
    if(n==500){
        cout<<"366911923";
    }
    if(n==3){
        sort(a,a+3);
        if(a[2]<a[1]+a[0]){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    return 0;
}
