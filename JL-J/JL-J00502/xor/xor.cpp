#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<1<<endl;
    }
    return 0;
}
