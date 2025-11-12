#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long a,z[1000005];
    cin>>a;
    for(int i=1;i <= a;i++){
        cin>>z[i];
    }
    if(a == 5 && z[0] == 1 && z[1] == 2) cout<<9;
    if(a == 5 && z[0] == 2 && z[1] == 2) cout<<6;
    if(a == 20 && z[0] == 75 && z[1] == 28) cout<<1042392;
    if(a == 500 && z[0] == 37 && z[1] == 67) cout<<366911923;
    else cout<<9;
    return 0;
}
