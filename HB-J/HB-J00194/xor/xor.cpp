#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s=0;cin>>n>>k;
    int a[N];cin>>a[1];
    a[0]=0;
    for(int i=2,v;i<=n;++i){
        cin>>v;
        a[i]=a[i-1]^v;
    }
    int l=1,r=1;
    while(l<=r&&r<=n){
        if((a[r]^a[l-1])==k){
            ++s;
            l=r+1,++r;
        }
        else if((a[r]^a[l-1])>k){
            if(((a[r]^a[l])-k)<((a[r+1]^a[l-1])-k))++l;
            else ++r;
        }
        else{
            if((k-(a[r]^a[l]))<(k-(a[r+1]^a[l-1])))++l;
            else ++r;
        }
        if(l>r)++r;
    }
    cout<<s;
    return 0;
}
