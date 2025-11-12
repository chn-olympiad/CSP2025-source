#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int c[505];
int t[505];
const int mod=998244353;
int ans=0;
int fact(int a){
    int res=1;
    for(int i=2;i<=a;i++){
        res*=i;
        res%=mod;
    }
    return res;
}
bool check(){
    int jet=0;
    for(int i=1;i<=n;i++){
        if(jet>=c[t[i]]||s[i-1]=='0'){
            jet++;
        }
    }
    return jet<=n-m;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    cin>>s;
    int c0=0;
    for(char i:s){
        if(i=='0')c0++;
    }
    int neoff=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        t[i]=i;
        if(c[i]==0)neoff++;
    }
    if(n==m){
        if(c0==0&&neoff==0){
            cout<<fact(n);
        }else{
            cout<<0;
        }
        return 0;
    }
    do{
        if(check()){
            ans++;
            ans%=mod;
        }
    }while(next_permutation(t+1,t+n+1));
    cout<<ans;
    return 0;
}
