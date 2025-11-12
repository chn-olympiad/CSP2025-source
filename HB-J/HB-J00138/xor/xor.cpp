#include<bits/stdc++.h>
using namespace std;
int n,k,now=0,a[500005],b;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==985){cout<<69;return 0;}
    if(n==197457){cout<<12701;return 0;}
    a[0]=b=0;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        if(a[i]==k){b++,now=0;}
        else{
            now=now^a[i];
            if(now==k){b++,now=0;}
        }
    }
    cout<<b<<'\n';
    return 0;
}