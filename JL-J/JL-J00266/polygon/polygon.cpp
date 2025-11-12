#include<bits/stdc++.h>
using namespace std;
int a[3];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int m;
    cin>>m;
    if(m<3){
        cout<<0;
        return 0;
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int ans=0;

    if(a[0]+a[1]+a[2]>2*max(max(a[0],a[2]),a[1])){
        ans++;

    }

    cout<<ans;
    return 0;
}
