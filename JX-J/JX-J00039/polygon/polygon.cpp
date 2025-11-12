#include<bits/stdc++.h>
using namespace std;
int n,a[15];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
    }else if(n==3){
        sort(a+1,a+4);
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}

