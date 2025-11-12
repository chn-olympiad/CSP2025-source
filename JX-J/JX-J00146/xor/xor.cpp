#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[1];
    return 0;
}
