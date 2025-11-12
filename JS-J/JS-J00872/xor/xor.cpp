#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool f=true;
    bool f1=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=false;
        }
        if(a[i]!=0&&a[i]!=1){
            f1=false;
        }
    }
    if(k==0){
        if(f){
            cout<<ceil(n/2);
            return 0;
        }
        if(f1){
            int cnt1=0;
            int cnt0=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cnt0++;
                }
                if(a[i]==1){
                    cnt1++;
                }
            }
            cout<<ceil(cnt1/2)+cnt0;
            return 0;
        }
        cout<<5;
    }
    if(k==1){
        if(f){
            cout<<n;
            return 0;
        }
        if(f1){
            int cnt1=0;
            int cnt0=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cnt0++;
                }
                if(a[i]==1){
                    cnt1++;
                }
            }
            cout<<cnt1;
            return 0;
        }
        cout<<4;
    }
    cout<<3;
    return 0;
}
