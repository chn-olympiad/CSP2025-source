#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz=200050;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    int a[sz];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int qq;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1]){
            cout<<a[i];
        }
        else{
            cout<<a[i+1];
        }
    }
    cout<<endl;
    return 0;
}
//By Mr.Han
