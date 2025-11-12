#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon,out","w",stdout);
    int n;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>20)
        cout<<1;
    return 0;
}
