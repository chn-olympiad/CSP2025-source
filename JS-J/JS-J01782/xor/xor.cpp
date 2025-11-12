#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,a[N],k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0) cnt0++;
        else cnt1++;
    }
    if(k==0) cout<<cnt0;
    else if(k==1) cout<<cnt1;
    else cout<<cnt0;
    return 0;
}
