#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m=0;
    int a[1000000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(n==3){
            sort(a[1],a[n],1);
            if(a[1]+a[2]>a[n]){
                m=1
                cout<<m;
            }
            else{
                cout<<m;
            }
        }
    }
    return 0;
}
