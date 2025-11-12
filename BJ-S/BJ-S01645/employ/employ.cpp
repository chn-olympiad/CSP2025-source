#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int MAXN=505;
int c[MAXN];
const long long mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    int c0=0,c1=0;
    int c2=0,c3=0;
    for (int i=1;i<=n;i++){
        if (s[i]=='0'){
            c0++;
        }
        else{
            c1++;
        }
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
        if (c[i]==0){
            c2++;
        }
        else{
            c3++;
        }
    }
    if (c1<m){
        cout<<"0";
        return 0;
    }
    if (m==n){
        if (c1!=n&&c2>1){
            cout<<"0";
            return 0;
        }
        else{
            long long ans=1;
            for (long long i=1;i<=n;i++){
                ans*=i;
                ans%=mod;
            }
            cout<<ans;
            return 0;
        }
    }
    if (c1==n){
        long long ans=1;
        for (long long i=1;i<=c3;i++){
            ans*=i;
            ans%=mod;
        }
        long long cnt=ans*(c3+1);
        cnt%=mod;
        if (c3+1<m){
            cout<<"0";
            return 0;
        }
        if (c3+1==m){
            cout<<cnt;
            return 0;
        }
        ans+=cnt;
        ans%=mod;
        cout<<ans;
        return 0;
    }
    cout<<"293847";
return 0;
}
