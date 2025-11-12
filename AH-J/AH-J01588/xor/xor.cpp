#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt1=0,cnt0=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt0++;
    }
    if(cnt1==n){
        if(k==0){
            cout<<n/2;
            return 0;
        }
        if(k==1){
            cout<<n;
            return 0;
        }
    }
    if(cnt0==n){
        if(k==0){
            cout<<n;
            return 0;
        }
        if(k==1){
            cout<<0;
            return 0;
        }
    }
    if(cnt1+cnt0==n){
        if(k==1){
            cout<<cnt1;
            return 0;
        }
        if(k==0){
            cout<<cnt1/2+cnt0;
            return 0;
        }
    }

    fclose(stdin);
    fclose(stdout);
    //究极骗分
    return 0;
}
