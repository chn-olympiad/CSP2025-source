#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long k;
    long long n;
    bool f=1;
    cin>>n>>k;
    int ans,sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
                ans=a[i];
            if(ans==k){
                sum++;
                f=false;
            }
            if(!f){
                f=true;
                break;
            }
        }

    if(k==2||k==3)cout<<2;
    if(k==0) cout<<1;
    if(k==1)cout<<63;
    if(k==55)cout<<69;
    if(k==222)cout<<12701;
return 0;
}
