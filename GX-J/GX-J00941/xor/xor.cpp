#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,cnt;
ll k;
ll a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k)cnt++;
    }
    cout<<cnt;
    return 0;
}
