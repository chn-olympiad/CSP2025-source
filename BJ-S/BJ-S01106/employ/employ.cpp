#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int c[1000001];
int q_pow(int x,int y){
    if(y==1)return x%mod;
    else if(y==0)return 1;
    int temp=q_pow(x,y/2)%mod;
    if(y%2==1)return temp*temp%mod*x%mod;
    else if(y%2==0)return temp*temp%mod;
}
int cnm(int x,int y){
    int ans=1;
    for(int i=x-y+1;i<=x;i++){
        ans*=i;
        ans%=mod;
    }
    for(int i=1;i<=x;i++){
        ans*=q_pow(i,mod-3);
        ans%=mod;
    }
    return ans%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long sum=1;
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=m;i<=n;i++){
        sum+=cnm(n,i);
        sum%=mod;
    }
    cout<<sum;
    return 0;
}
