#include<bits/stdc++.h>
#define N 1000010
#define mod 998244353
using namespace std;
int n, m;
string s;
long long ans=0, sum=0, cnt=0;
inline int read(){
    char ch=getchar(); int x=0, f=1;
    while(!isdigit(ch)) {f=(ch=='-')?-1:1; ch=getchar();}
    while(isdigit(ch)) {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n=read(); m=read();
    cin >> s; int len=s.size(), flag=0, e=0;
    for(int i=0; i<len; i++){
        if(s[i]=='0') flag=1;
        if(s[i]==1&&e==0) e=i+1;
    }
    //if(!flag){
        ans=1, sum=0; cnt=0;
        for(int i=1; i<=n; i++){
            int a=read();
            sum += (a==0);
            if(a>=e) cnt++;
        }
    if(m==1){
        ans = cnt;
        for(int i=2; i<=n; i++);
            ans = (ans*i)%mod;
        printf("%lld", ans);
        return 0;
    }
        for(int i=1; i<=n-sum; i++)
            ans = (ans*i)%mod;
        printf("%lld", ans);
        return 0;
    //}
    return 0;
}
