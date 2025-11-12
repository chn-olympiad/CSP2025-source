#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
int flag=1;
int z=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    flag=1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(s[i]=='0'){
            flag=0;
        }
        if(s[i]=='1'){
            z++;
        }
    }
    if(flag==1){
        if(m>n){
            cout<<0;
            return 0;
        }
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i%mod;
        }
        cout<<ans;
        return 0;
    }
    else if(m==n){
        if(flag==0){
            cout<<0;
            return 0;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        if(m>z){
            cout<<0;
            return 0;
        }
    }
    return 0;
}
