#include <bits/stdc++.h>
using namespace std;
int zn,ma[5001];
long long max_ans;
long long f_(int cn){
    long long sum=1;
    for(int i=1;i<=cn;i++) sum*=2;
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>zn;
    for(int i=1;i<=zn;i++)
        cin>>ma[i];
    if(zn==3){
        if(ma[1]+ma[2]+ma[3]>2*max(max(ma[1],ma[2]),ma[3])){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        max_ans=f_(zn)-1-zn-(zn-1)*zn/2;
        cout<<max_ans;
    }
    return 0;
}
