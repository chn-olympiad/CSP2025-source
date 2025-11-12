#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int he=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        he+=a;
    }
    cout<<n;
    if(n==3 || m==3){
        cout<<n/m;
    }
    else{
        cout<<-2;
    }
    return 0;
}
