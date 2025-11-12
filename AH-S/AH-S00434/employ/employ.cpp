#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
using namespace std;
const int dd=1e6+5;
const int M=998244353;
int c[dd],pre[dd];int n,m;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    n=read(),m=read();
    string s;cin>>s;int ans=0;
    for(int i=1;i<=n;i++)c[i]=read();
    for(int i=1;i<=n;i++)pre[i]=i;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(cnt>=c[pre[i]]||s[i-1]=='0'){cnt++;continue;}
        ans+=(n-cnt>=m);ans%=M;
    }while(next_permutation(pre+1,pre+1+n));
    printf("%lld",ans%M);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
