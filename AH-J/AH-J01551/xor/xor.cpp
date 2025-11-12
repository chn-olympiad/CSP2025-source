#include<bits/stdc++.h>
using namespace std;
long long xo[500005];
long long a[500005];
bool c[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xo[i]=(xo[i-1]^a[i]);
        //cout<<xo[i]<<" ";
    }
    //cout<<"\n";
    int l=1,r=1,n1=0;
    while(l<=r&&r<=n){
        if((xo[r]^xo[l-1])==k&&!c[l]){
            n1++;
            for(int i=l;i<=r;i++){
                c[i]=1;
            }
            //cout<<(xo[r]^xo[l-1])<<"\n";
            l=r+1;
            r=l;
        }
        r++;
        if(r>n){
            l++;
            r=l;
        }
    }
    cout<<n1;
    return 0;
}
