#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    sort(a,a+n);
    if(n==3){
        if(a[0]+a[1]+a[2]>2*a[2]){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<((n-2)+1) * (n-2) / 2;
    }
    return 0;
}
