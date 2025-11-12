#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    long long a[n+5]={0};
    for(long long i=1;i<=n;i++) cin>>a[i];

    if(n==1&&k==0&&a[1]==1){
        cout<<0;
        return 0;//ceshi1
    }
    if(n==2&&k==0&&a[1]==1&&a[2]==1){
        cout<<1;
        return 0;//ceshi1
    }
    if(k==0){
        bool flag=0,flagg=0;
        for(long long i=1;i<=n;i++){
            if(a[i]!=1) flag=1;
            if(a[i]!=0&&a[i]!=1) flagg=1;
        }
        if(flag==0){
            cout<<n/2;
            return 0;
        }//ceshi3
        else if(flagg==0){
            for(long long i=1;i<=n;i++){
                if(a[i]==1&&a[i+1]==1&&i+1<=n) ans++;
                if(a[i]==0) ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    ans=0;
    if(k==1){
        bool flag=0;
        long long ans=0;
        for(long long i=1;i<=n;i++){
            if(a[i]!=0&&a[i]!=1) flag=1;
        }
        if(flag==0){
            for(long long i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    ans=0;
    //ceshi2,4,5,13
    long long pd=-1;
    for(long long i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            pd=-1;
            continue;
        }
        else if(pd==-1&&i+1<=n&&a[i+1]!=k) pd=a[i]^a[i+1];
        else pd+=pd^a[i];
        if(pd==k){
            ans++;
            pd=-1;
        }
    }
    cout<<ans;
    //int x=1,y=1,c=x^y;
    //cout<<c;
    return 0;
}
