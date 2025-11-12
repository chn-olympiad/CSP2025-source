#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(a[0]+a[1]>a[2]) cout<<1;
    else cout<<0;
    return 0;
}
