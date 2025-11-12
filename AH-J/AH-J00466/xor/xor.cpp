#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k,a[500001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(unsigned long long i=0;i<n;++i){
        cin>>a[i];
    }
    unsigned long long he=a[0],ans=0,l=0,r=0;
    while(r<n){
        if(he==k){
            ++ans;
            l=r+1;
            r=l;
            he=a[l];
        }else if(r==n-1){
            r=l+1;
            l=r;
            he=a[l];
        }else{
            he^=a[++r];
        }
    }
    cout<<ans;
    return 0;
}
