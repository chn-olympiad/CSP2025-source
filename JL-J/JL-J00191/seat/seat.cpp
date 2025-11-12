#include<bits/stdc++.h>
using namespace std;
int textn[150];
int myans=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int myn,mym;
    cin>>myn>>mym;
    int i=0;
    for(;i<myn*mym;i++){
        cin>>textn[i];
    }
    int j=1;
    for(;j<myn*mym;j++){
        if(textn[j]>textn[0]){
            myans++;
        }
    }
    if(myans%myn==0){
        cout<<myans/myn<<" ";
        if((myans/myn)%2){
            cout<<myn;
        }else{
            cout<<1;
        }
    }else{
        cout<<((myans/myn)+1)<<" ";
        if((myans/myn+1)%2){
            cout<<myn-myans+1;
        }else{
            cout<<myn;
        }
    }
    return 0;
}
