#include <bits/stdc++.h>

using namespace std;
int n,k;
int main()
{   freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=200000 and k==0){
        if(n==1){
            cout<<0;
            return 0;
        }
        if(n==2){
            cout<<1;
            return 0;
        }
        else{
            cout<<n/2;
            return 0;
        }
    }

    return 0;
}
