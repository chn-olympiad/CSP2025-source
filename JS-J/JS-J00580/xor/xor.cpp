#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int cnt=0;
    if(k==0){
        for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
    }
    else{
        for(int i=1;i<=n;i++)if(a[i]==1)cnt++;
    }
    cout<<cnt;
    return 0;
}
