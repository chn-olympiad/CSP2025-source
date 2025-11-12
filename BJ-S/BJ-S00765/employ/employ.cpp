#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a[505],c[505];
const long long N=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    bool flag=true;
    for(int i=0;i<s.size();i++){
        a[i+1]=int(s[i]-'0');
        if(a[i+1]!=1){
            flag=false;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]<=cnt){
            cnt++;
        }
    }
    if((cnt!=n)&&m==1){
        cout<<n-cnt<<endl;
        return 0;
    }
    if((cnt==0)&&m==n){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=n-i+1;
            ans%=N;
        }
        cout<<ans<<endl;
        return 0;
    }
    if((cnt!=0)&&m==n){
        cout<<0<<endl;
        return 0;
    }
    if((n-cnt)<m){
        cout<<0<<endl;
        return 0;
    }
    return 0;
}

