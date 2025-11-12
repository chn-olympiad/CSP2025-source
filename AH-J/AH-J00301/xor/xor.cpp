#include<bits/stdc++.h>
using namespace std;
long long n,a[600000],k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(k==0){
        if(n%2==0){
            cout<<n;
            return 0;
        }
        else if(n%2==1){
            cout<<n-1;
            return 0;
        }
    }
    return 0;
}
