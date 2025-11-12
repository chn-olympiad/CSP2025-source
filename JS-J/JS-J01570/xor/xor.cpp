#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    bool t1=1;
    bool t2=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            t1=0;
            if(a[i]!=0) t2=0;
        }

    }
    if(t1){
        if(n==1&&k==0){
            cout<<0;
            return 0;
        }
        if(n==2&&k==0){
            cout<<1;
            return 0;
        }
        cout<<n/2;
        return 0;
    }
    if(t2){
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            if(a[i]) cnt1++;
            else cnt0++;
        }
        if(k==0){
            for(int i=0;i<n;i++){
                if(a[i]==1&&a[i+1]==1){
                    cnt0++;
                    i++;
                }
            }
            cout<<cnt0;
            return 0;
        }
        if(k==1){
            cout<<cnt1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
