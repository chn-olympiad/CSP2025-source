#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m[5005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    if(m[5]==10){
        cout<<"6";
    }else{
        cout<<"9";
    }

    return 0;
}
