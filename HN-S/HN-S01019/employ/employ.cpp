#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void file(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
}

const int N=505,mod=998244353;
int n,m,a[N],b[N],fac[N];
string s;

inline int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

signed main(){
    file();
    
    n=read(),m=read();
    cin>>s;
    bool flag=0;
    for(int i=0;i<n;i++){
        int x=s[i]-'0';
        if(!x) flag=1;
    }
    for(int i=1;i<=n;i++)
        a[i]=read();
    if(!flag){
        fac[0]=1;
        for(int i=1;i<=n;i++)
            fac[i]=fac[i-1]*i%mod;
        cout<<fac[n]<<"\n";
        return 0;
    }   
    int ans=0,cnt=0;
    
    return 0;
}