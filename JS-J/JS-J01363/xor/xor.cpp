#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,flag=0,cnt=0,flag1=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=1;
        if(a[i]!=0&&a[i]!=1)flag1=1;
    }
    if(flag==0){
        if(k==0)cout<<n/2;
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==1)cnt++;
                if(a[i]==0){
                    if(a[i+1]==1){
                        cnt++;
                        i++;
                    }
                }
            }
            cout<<cnt;
        }
        return 0;
    }
    if(flag1==0){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0)cnt++;
                if(a[i]==1){
                    if(a[i+1]==1){
                        cnt++;
                        i++;
                    }
                }
            }
            cout<<cnt;
            return 0;
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==1)cnt++;
                if(a[i]==0){
                    if(a[i+1]==1){
                        cnt++;
                        i++;
                    }
                }
            }
            cout<<cnt;
            return 0;
        }
    }
    return 0;
}
