#include <bits/stdc++.h>
using namespace std;
int n,k,a[200050],b[200005],tff,cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool oo=1,boaz=1,tff=255;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)oo=0;
        if(a[i]!=1&&a[i]!=0)boaz=0;
        if(a[i]>tff)tff=0;
    }
    if(oo){
        if(k!=0&&k!=1){
            cout<<0;
            return 0;
        }
        if(k==0){
            cout<<n/2;
            return 0;
        }
        if(k==1){
            cout<<n;
            return 0;
        }
    }
    if(boaz){
        int qd=0;
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    if(b[cnt-1]!=k)qd++;
                }
                else{
                    b[cnt]^=a[i];
                    if(b[cnt]==1)cnt++;
                }
            }
            cout<<cnt-qd;
            return 0;
        }
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    if(b[cnt-1]!=k)qd++;
                    cnt++;
                }
                else{
                    b[cnt]^=a[i];
                    if(b[cnt]==0)cnt++;
                }
            }
            cout<<cnt-qd;
            return 0;
        }
    }
    int qdd=0;
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            if(b[cnt-1]!=k){
                qdd++;
            }
        }
        else{
            b[cnt]^=a[i];
            if(b[cnt]==0)cnt++;
        }
    }
    cout<<cnt-qdd;
    return 0;
    srand(time(0));
    cout<<rand();
    return 0;
}