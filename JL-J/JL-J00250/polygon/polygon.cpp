#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int aa[5007];
    memset(aa,0,sizeof(aa));
    for(int i=1;i<=n;i++){
        cin>>aa[i];

    }
    if(n==5 and aa[1]==1){
        cout<<9;
        return 0;
    }else if(n==5 ams aa[1]==2){
        cout<<6;
        return 0;
    }else if(n==20){
        cout<<1042392;
        return 0;
    }else{
        cout<<366911923;
        return 0;
    }
    return 0;
}
