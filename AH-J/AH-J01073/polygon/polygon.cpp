#include<bits/stdc++.h>
using namespace std;
int sum[5005],a[5005];
int main(){
    int n;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c) cout<<1;
        else cout<<0;
        return 0;
    }
    cout<<0;
    return 0;
}
