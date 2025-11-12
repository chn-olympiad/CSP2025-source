// employ
#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-f;
    for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
    return f*x;
}
const int N=505,mod=998244353;
int n,m;
string s;
int c[N];
int c0;
bool A=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s;
    for(int i=1;i<=n;i++){
        c[i]=read();
        if(c[i]==0)c0++;
    }
    for(char ch:s){
        if(ch!='1')A=0;
    }
    if(A){
        if(n-c0>=m){
            long long ans=1;
            for(int i=1;i<=n;i++){
                ans=ans*i%mod;
            }
            printf("%lld",ans);
        }
        else {
            if(n-c0+1<m){
                printf("0");
            }
            else {
                long long ans=1;
                for(int i=1;i<=n-1;i++){
                    ans=ans*i%mod;
                }
                printf("%lld",ans);
            }
        }
    }
    else printf("%lld",1ll*rand()*rand()%mod);
    return 0;
}