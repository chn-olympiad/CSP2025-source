#include<bits/stdc++.h>
using namespace std;
int n,a[1005],Max=-1,l;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l+=a[i];
        Max=max(Max,a[i]);
    }
    if(l>Max*2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
