#include<bits/stdc++.h>
using namespace std;

int a[100000],b[100000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum=0,ans=1,sum2=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        a[i+1]=s[i]-48;
        if(a[i+1]==1){
            sum++;
        }
        if(a[i+1]==1){
            sum2++;
        }
    }
    if(sum==n){
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    if(m==1){
        if(sum2==n){
            cout<<0;
            return 0;
        }
        else{
            for(int i=1;i<=n;i++){
                ans*=i;
                ans%=998244353;
            }
            cout<<ans;
            return 0;
        }
    }
    if(m==n){
        if(sum==n){
            for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    return 0;
}
