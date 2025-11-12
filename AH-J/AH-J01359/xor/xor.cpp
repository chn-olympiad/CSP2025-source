#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,a1=0,a2=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            a1=1;
        }
        if(a[i]>1){
            a2=1;
        }
    }
    if(a1==0&&k==0){
        cout<<n/2;
    }
    else if(a2==0&&k<=1){
        if(k==0){
            int cnt=0,cc=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cnt++;
                }
                if(a[i]==1){
                    cc++;
                }
            }
            cout<<cnt+cc/2;
        }
        else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
            cout<<cnt;
        }
    }
    else{
        int tt=0,sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=k){
                tt=1;
            }
            sum^=a[i];
        }
        if(tt==0){
            cout<<n;
        }
        else if(sum==k){
            cout<<1;
        }else{
            cout<<n/2;
        }
    }

return 0;}
