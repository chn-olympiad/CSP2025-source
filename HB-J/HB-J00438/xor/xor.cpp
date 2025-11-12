#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long  n,k;
    cin>>n>>k;
    long long  a[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1)a[i]=(a[i]^a[i-1]);
    }

    long long  conts=0,ll=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=ll;j--){
            if(a[i]^a[j]==k){
                cout<<i;
                if(i-j>conts) conts=i-j;
                ll=i;
            }
        }
    }
   cout<<conts;
    return 0;


}

