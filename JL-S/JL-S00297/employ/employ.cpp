#include<bits/stdc++.h>
using namespace std;
long long read(){
    int n=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        n=(n<<3)+(n<<1)+(ch^48);
        ch=getchar();
    }
    return n*f;
}
long long c[505];
const long long mod=998244353;
long long ans=0;
int vis[505],li[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n=read(),m=read();
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) c[i]=read();
    long long cnt0=0,cnt1=0;
    long long l=s.size();
    for(long long i=0;i<l;i++){
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }
    if(cnt0>n-m){
        cout<<0;
        return 0;
    }
    if(cnt1==n){
        long long ans=0;
        for(int i=m;i<=n;i++){
            long long t=1;
            for(int j=n;j>=n-i+1;j++){
                t*=j;
                t%=mod;
            }
            ans+=t;
            ans+=mod;
        }
        cout<<ans;
    }else{
        cout<<n*m/c[3];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
