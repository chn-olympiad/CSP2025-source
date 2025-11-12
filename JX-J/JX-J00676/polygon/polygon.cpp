#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        x+=a[i];
        y=max(y,a[i]);
    }
    if(x>2*y)cout<<1;
    else cout<<0;
    return 0;
}
