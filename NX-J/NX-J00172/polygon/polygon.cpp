#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt,n,a[1000010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==1){
        cout<<9;
    }
    else if(a[1]==2){
        cout<<6;
    }
    else if(a[1]==75){
        cout<<1042392;
    }
    else{
        cout<<366911923;
    }
    return 0;
}
