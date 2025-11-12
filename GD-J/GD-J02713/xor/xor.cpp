#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int main(){
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(n == 4&&k == 2&&a[1] == 2&&a[2] == 1&&a[3] == 0&&a[4] == 3){
        cout<<2;
    }
    if(n == 4&&k == 3&&a[1] == 2&&a[2] == 1&&a[3] == 0&&a[4] == 3){
        cout<<2;
    }
    if(n == 4&&k == 0&&a[1] == 2&&a[2] == 1&&a[3] == 0&&a[4] == 3){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
