#include<bits/stdc++.h>
using namespace std;
long long a[1010101];
long long n;
long long k;
long long c;
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        c=c^a[i];
        if(c==k){
            c=0;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

