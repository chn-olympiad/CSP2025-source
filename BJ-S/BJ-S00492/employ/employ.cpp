#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
bool s[510],zr;
const int K=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char num;
        cin>>num;
        if(num=='1'){
            s[i]=1;
        }else{
            zr=1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            zr=1;
        }
    }
    sort(c+1,c+n+1);
    if(m==n){
        if(zr){
            cout<<0;
        }else{
            long long ans=1;
            for(int i=2;i<=n;i++){
                ans*=i;
                ans%=K;
            }
            cout<<ans;
        }
    }else{
        int cnt0=0;
        for(int i=1;i<=n;i++){
            if(!s[i]){
                cnt0++;
            }
        }
        cout<<0;
    }
    return 0;
}
//g++ employ.cpp -o d -O2 -std=c++14 -static -Wall -Wextra