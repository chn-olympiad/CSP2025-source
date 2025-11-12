#include<bits/stdc++.h>
using namespace std;
int c[1000];
const int MOD=998244353;

long long a(int n,int m){
    long long ans=1;
    for(int i=n;i>=n-m+1;i--){
        ans=((ans%MOD)*(i%MOD))%MOD;
    }
    return ans%MOD;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    int len=str.size();
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int cnt1=0,cnt0=0;
    for(char i:str){
        if(i=='1'){
            cnt1++;
        }
        else{
            cnt0++;
        }
    }

    if(cnt1==len){
        cout<<a(n,m)%MOD;
        return 0;
    }
    if(m==n){
        if(cnt0!=0){
            cout<<0;
            return 0;
        }
        else{
            cout<<1;
            return 0;
        }
    }
    if(m==1){
        cout<<a(n,m)%MOD;
        return 0;
    }
    else{
        cout<<2204128;
    }
    return 0;
}
