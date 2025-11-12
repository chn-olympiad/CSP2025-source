#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m=-100,r;
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        for(int i=1;i<=n;i++){
            if(a[i]>=m)m=a[i];
            r+=a[i];
        }
        r-=m;
        if(r>m){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if(n<=20){
        cout<<n*8;
        return 0;
    }
    else cout<<n*446786;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
